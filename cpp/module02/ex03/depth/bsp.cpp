#include "Fixed.hpp"
#include "Point.hpp"
#include <fstream>
#define DEPTH 10

struct s_bsp
{
	Point point;
	struct s_bsp *cside;
	struct s_bsp *bside;
};

void 	print_node(s_bsp *node, std::ofstream &out)
{
	// out << "Point = " << node->point << std::endl;	
	out << node->point << std::endl;	
}

void	print_map(s_bsp *map, std::ofstream &out)
{
	print_node(map, out);
	if (map->cside)
	{
		// out << "To the cside : " << std::endl;
		print_map(map->cside, out);
	}
	if (map->bside)
	{
		// out << "To the bside : " << std::endl;
		print_map(map->bside, out);
	}
}

void	init_map(s_bsp *map, Point const &a, Point const &b, Point const &c, int &nodes, int &depth)
{
	map->point = Point::getmidpoint(b, c);
	nodes++;
	depth--;
	Point midp = map->point; 

	if (((a == b) && (b == c)) || (midp == a) || (midp == b) || (midp == c) || !depth)
	{
		if (!depth)
			depth = DEPTH;
		map->cside = NULL;
		map->bside = NULL;
		return ;
	}
	map->cside = new s_bsp;
	map->bside = new s_bsp;
	init_map(map->cside, midp, a, c, nodes, depth);
	init_map(map->bside, midp, a, b, nodes, depth);
}

void	delete_stuff(s_bsp *map)
{
	s_bsp *l_temp, *r_temp;

	l_temp = map->cside;
	r_temp = map->bside;

	delete map;

	if (l_temp)
		delete_stuff(l_temp);
	if (r_temp)
		delete_stuff(r_temp);
}

void	find_point(s_bsp *map, Point const &point, bool &val)
{
	if (map->point == point)
		val = 1;
	else
	{
		if (map->cside)
			find_point(map->cside, point, val);
		if (map->bside)
			find_point(map->bside, point, val);
	}
	return ;
}

bool invalid( Point const &a, Point const &b, Point const &c, Point const &point)
{
	if (a == point || b == point || c == point)
		return (1);
	return (0);
}

// a, b, c vertices of triangle, point -> to search
bool bsp( Point const a, Point const b, Point const c, Point const point)
{	
	int depth = DEPTH;
	bool val;
	std::cout << "In bsp" << std::endl;
	if (invalid(a, b, c, point))
		return 0;

	s_bsp *map = new s_bsp;

	map->cside = NULL;
	map->bside = NULL;

	std::cout << "Initializing a map..." << std::endl;
	int nodes = 0;
	init_map(map, a, b, c, nodes, depth);
	std::cout << "Map initialization complete!" << " Nodes = " << nodes << std::endl;

	std::ofstream mapfile;

	mapfile.open("mapfile.map", std::ios::trunc | std::ios::out);
	std::cout << "Writing to mapfile..." << std::endl;
	print_map(map, mapfile);

	find_point(map , point, val);
	delete_stuff(map);
	return (val);
}
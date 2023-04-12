print "Enter a string = ";
$string = <>;
chomp($string); ## remove idiot \n
$index = 0;

$len = length($string);

$index = 0;
$end = $len - 1;

while ($index != $len && $index != $end)
{
	$front = substr($string, $index, 1);
	$back = substr($string, $end, 1);
	if ($front ne $back)
	{
		print "The string is not a palindrome\n";
		exit;
	}
	++$index;
	--$end;
}

print "The string is a palindrome\n";
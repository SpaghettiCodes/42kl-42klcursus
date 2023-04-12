print ("enter string lmao = ");
chomp($str = <>);

if ( $str eq reverse($str) ) {
     print "PALINDROME!\n";
}
else {
     print "NOT A PALINDROME! \n";
}
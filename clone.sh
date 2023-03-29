echo "If your SSH key has a passphrase, you might need to enter it each time. Consider using ssh-agent or removing the passphrase";

while read p; do
	echo "$p";
	git -C .lib clone "$p";
done < $1
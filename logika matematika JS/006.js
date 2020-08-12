<script>
function rekrusif(n) {
	if (n === 0) return;
	document.write(n);
	return rekrusif(n-2) 
}
rekrusif (10);
</script>

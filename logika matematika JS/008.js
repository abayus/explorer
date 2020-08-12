<script>
var output = prompt("Inputkan jenis output (+ atau =) : ");
 
var val1 = 9;
var val2 = 10;
 
if (output == '+') {
	var result = val1+val2;
}
else if (output == '=') {
	var result = val1=val2;
}

alert('Output dari '+val1+output+val2+' = '+result);
</script>
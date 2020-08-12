<script>
    var nilai = [10, 2, 9]
    var max = nilai[0];
    var min = nilai[0];
    var sum = nilai[0]; 
    for (var i = 1; i < nilai.length; i++) {
        if (nilai[i] > max) {
            max = nilai[i];
        }
        if (nilai[i] < min) {
            min = nilai[i];
        }
        sum = sum + nilai[i];
    }
  document.write('output nilai maksimal adalah = ' +max);
  document.write("<hr>")
  document.write('output nilai minimum adalah = '  +min);
  document.write("<hr>")
  document.write('output nilai rata-rata adalah = ' + sum/nilai.length); 
</script>

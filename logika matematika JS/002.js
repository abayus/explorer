        <form method="post">
            Inputkan nilai:  <input type="number" id="nilai" name="nilai" min="0" /><input type="button" value="genap atau ganjil?" onclick="findOddEven()" name="cari" />
            <div style="margin-top: 5px;" id="result"></div>
        </form>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <script>
            function findOddEven(){
                var nilai = document.getElementById('nilai').value;

                if ( nilai % 2 == 0) {
                    document.getElementById('result').innerHTML = nilai + ' adalah genap';
                }else{
                    document.getElementById('result').innerHTML = nilai + ' adalah ganjil';
                }
            }        
        </script>

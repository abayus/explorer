<script>
function leapYear(input) {
    let year = input;
    let nilai;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        nilai = "adalah tahun kabisat";
    } else {
        nilai = "adalah bukan tahun kabisat";
    }
    document.write(nilai);
} 
leapYear(2004);
document.write("<hr>");
leapYear(2008);
document.write("<hr>");
leapYear(2012);
document.write("<hr>");
leapYear(1900);
document.write("<hr>");
leapYear(2100);
document.write("<hr>");
leapYear(1600);
document.write("<hr>");
leapYear(200);
document.write("<hr>");
leapYear(2009);
</script>

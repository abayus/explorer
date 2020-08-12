<script>

function palindrome(text) {
  text = text.toUpperCase().replace(/\W/g, '');
  return text === text.split('').reverse().join('');
}

document.write(palindrome('Cigar? Toss it in a can. It is so tragic'));
document.write("<hr>");
document.write(palindrome('I did, did I?'));
document.write("<hr>");
document.write(palindrome('Red rum, sir, is murder'));
document.write("<hr>");
document.write(palindrome('Eva, can I see bees in a cave?'));
document.write("<hr>");
document.write(palindrome('Hello World'));
</script>

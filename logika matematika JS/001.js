    <script>
        var grade = prompt("inputkan nilai: ")
        var output = "";

        if(grade >= 90) output = "A"
        else if(grade >= 80) output = "B"
        else if(grade >= 70) output = "C"
        else if(grade >= 60) output = "D"
        else output = "E";

        document.write(`<p>output: ${output}</p>`);
    </script>
<script>
const json = [
  { id: '1', name: 'Udin', age: 12 },
  { id: '2', name: 'Reane', age: 51 },
  { id: '3', name: 'Budi', age: 34 },
  { id: '4', name: 'Agus', age: 16 },
  { id: '5', name: 'Sari', age: 19},
  { id: '6', name: 'Ririn', age: 20 },
  { id: '7', name: 'Dessy', age: 23 },
]

const filterage = []

for (let i = 0; i < json.length; i++) {
  if (json[i].age <= 21) {
    filterage.push(json[i].name);
  }
}

document.write(filterage)
</script>

const fruits = ['apple', 'banana', 'cherry', 'date', 'elderberry'];

console.log(fruits.slice(1, 3));    // ['banana', 'cherry']
console.log(fruits.slice(2));       // ['cherry', 'date', 'elderberry']
console.log(fruits.slice(-2));      // ['date', 'elderberry']
console.log(fruits.slice(1, -1));   // ['banana', 'cherry', 'date']
console.log(fruits);                // Original array is unchanged
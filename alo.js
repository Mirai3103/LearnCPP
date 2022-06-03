const arr = [1, 2, 3, 4, 5];

let Tongcua2 = [];
for (let i = 0; i < arr.length; i++) {
  for (let j = i + 1; j < arr.length; j++) {
    Tongcua2.push({
      sum: arr[i] + arr[j],
      index: [i, j],
    });
  }
}

let boi3 = [];

boi3 = arr.map((a) => a * 3);

let boi3MinusArr = [];
for (let i = 0; i < boi3.length; i++) {
  for (let j = 0; j < arr.length; j++) {
    if (boi3[i] - arr[j] > Tongcua2[0].sum) {
      boi3MinusArr.push({
        sum: boi3[i] - arr[j],
        index: j,
      });
    }
  }
}

Tongcua2.sort((a, b) => a.sum - b.sum);
let ketqua = new Set();
for (let i = 0; i < boi3MinusArr.length; i++) {
  for (let j = 0; j < Tongcua2.length; j++) {
    if (boi3MinusArr[i].sum === Tongcua2[j].sum) {
      if (
        arr[boi3MinusArr[i].index] != arr[Tongcua2[j].index[0]] &&
        arr[Tongcua2[j].index[0]] != arr[Tongcua2[j].index[1]] &&
        arr[Tongcua2[j].index[1]] != arr[boi3MinusArr[i].index]
      ) {
        let tem = [
          arr[boi3MinusArr[i].index],
          arr[Tongcua2[j].index[0]],
          arr[Tongcua2[j].index[1]],
        ];
        tem.sort((a, b) => a - b);
        let str = JSON.stringify(tem);
        ketqua.add(str);
      }
    }
  }
}
console.log(ketqua);

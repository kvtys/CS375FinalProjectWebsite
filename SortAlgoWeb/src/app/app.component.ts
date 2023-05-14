import { HttpClient } from '@angular/common/http';
import { Component } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'SortAlgoWeb';
  newArr: number[];
  step: string;
  partition: string;

  constructor(private http: HttpClient, private router: Router){
    this.newArr = [0];
    this.step = "";
    this.partition = "";
  }
  

  swap(arr: number[], i: number, j: number): number[] {
      const temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;

      return arr;
  }

  async selectionSort(arr: number[]): Promise<number[]>{
    this.step = "";
      const size = arr.length;
      let c = 0;
      for (let i = 0; i < size - 1; i++) {
          for (let j = i + 1; j < size; j++) {
              if (arr[i] > arr[j]) { 
                this.swap(arr, i, j);
                this.step = this.step + ' --> ' + `Step ${c + 1}: Swap ${arr[i]} and ${arr[j]} to get ${arr.join(', ')}`; //this will show up on the website itself, showing intermediate steps 
                await this.delay(2000);
                c++;
              }
          }
      }
      this.step = this.step + " --> Finished! ";
      return arr;
  }

  async insertionSort(arr: number[]): Promise<number[]> {
    this.step = "";
      const size = arr.length;
      let c = 0;
      for (let i = 1; i < size; i++) {
          const key = arr[i];
          let j = i - 1;

          while (j >= 0 && arr[j] > key) {
              arr[j + 1] = arr[j];
              j--;
          }
          arr[j + 1] = key;
          this.step = this.step + ' --> ' + `Step ${c + 1}: Insert ${arr[j+1]} after ${arr[j]} to get ${arr.join(', ')}`;
          await this.delay(2000);
          c++;
      }

      this.step = this.step + " --> Finished!";
      return arr;
  }

  delay(ms: number): Promise<void> {
    return new Promise((resolve) => setTimeout(resolve, ms));
  }
  
  async bubbleSort(arr: number[]): Promise<number[]> {
    this.step = "";
    console.log("this is the starting arr " + arr.toString());
    const n = arr.length;
    let swapped: boolean;
    
    let c = 0
    for (let i = 0; i < n - 1; i++) {
      swapped = false;
  
      for (let j = 0; j < n - 1 - i; j++) {
        if (arr[j] > arr[j + 1]) {
          // Swap elements
          console.log("the number " + arr[j].toString() + " is greater than the number " + arr[j+1].toString());

          this.swap(arr, j, j+1);
          swapped = true;
          this.step = this.step + ' --> ' + `Step ${c + 1}: Swap ${arr[j+1]} and ${arr[j]} to get ${arr.join(', ')}`; //this will show up on the website itself, showing intermediate steps 
          await this.delay(2000);
          c++;
        }
      }
  
      // If no two elements were swapped in the inner loop, the array is already sorted
      if (!swapped) {
        break;
      }

    }
    this.step = this.step + " --> Finished! ";
    console.log("this is the end arr: " + arr);
    return arr;
  }

  async qPartition(arr: number[], left: number, right: number): Promise<number> {
    let pivot   = arr[Math.floor((right + left) / 2)], 
        i       = left, 
        j       = right;
    
    while (i <= j) {
      while (arr[i] < pivot) {
        i++;
      }
      while (arr[j] > pivot) {
        j--;
      }
      if (i <= j) {
        [arr[i], arr[j]] = [arr[j], arr[i]]; // Swap values
        this.step = this.step + `--> Swapped ${arr[j]} and ${arr[i]}: to get ${arr.join(', ')} with pivot ${pivot}`;
        await this.delay(2000);
        i++;
        j--;
      }
    }
    return i;
  }

  
  async quickSort(arr: number[], left = 0, right = arr.length - 1): Promise<number[]> {
    let index;
    let c = 0;
    if (arr.length > 1) {
      index = await this.qPartition(arr, left, right); 
      if (left < index - 1) { 
        this.quickSort(arr, left, index - 1);
      }
      if (index < right) { 
        this.quickSort(arr, index, right);
      }
    }
    return arr;
  }

  async mergeSort(arr: number[]): Promise<number[]> {
    if (arr.length <= 1) {
      return arr;
    }

    const mid = Math.floor(arr.length / 2);
    const left = arr.slice(0, mid);
    const right = arr.slice(mid);

    return await this.merge1(
      await this.mergeSort(left),
      await this.mergeSort(right)
    );
  }

  async merge1(left: number[], right: number[]): Promise<number[]> {
    let resultArray = [], leftIndex = 0, rightIndex = 0;

    while (leftIndex < left.length && rightIndex < right.length) {
      if (left[leftIndex] < right[rightIndex]) {
        resultArray.push(left[leftIndex]);
        leftIndex++;
      } else {
        resultArray.push(right[rightIndex]);
        rightIndex++;
      }
    }

    // Concatenating the remaining elements, in case one array was larger
    const result = resultArray
      .concat(left.slice(leftIndex))
      .concat(right.slice(rightIndex));
    
    this.step = this.step + ' --> Current merged array:' + result;
    await this.delay(2000);
    return result;
  }


  chooseAlgo(message: {arr: any, algo: number}): number[] {
    if(message.arr != ""){
      this.newArr = message.arr.split(",");

      //THIS IS FOR DEBUGGING - AMEEN

      for(let i = 0; i < this.newArr.length; i++ ){
        console.log(this.newArr[i]);
        if(this.newArr[i] < this.newArr[i+1]){
          console.log(this.newArr[i].toString() + " < " + this.newArr[i+1].toString());
        }
      }

      //DEBUGGING END

      if(message.algo == 1){
        console.log(this.bubbleSort(this.newArr)); 
      }
      else if(message.algo == 2){
        console.log(this.selectionSort(this.newArr));
      }
      else if(message.algo == 3){
        console.log(this.insertionSort(this.newArr));
      }
      else if(message.algo ==4){
        this.step = "";
        console.log(this.quickSort(this.newArr, 0, this.newArr.length - 1));
      }
      else if(message.algo ==5){
        this.step = "";
        console.log(this.mergeSort(this.newArr));
      }
      else{
        this.step = "Not a proper number!";
        return [0];
      }
    }

    return[0];

  }
}

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

  constructor(private http: HttpClient, private router: Router){
    this.newArr = [0];
    this.step = "";
  }
  

  swap(arr: number[], i: number, j: number): void {
      const temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
  }

  selectionSort(arr: number[]): number[] {
      const size = arr.length;

      for (let i = 0; i < size - 1; i++) {
          for (let j = i + 1; j < size; j++) {
              if (arr[i] > arr[j]) {
                  this.swap(arr, i, j);
              }
          }
      }

      return arr;
  }

  insertionSort(arr: number[]): number[] {
      const size = arr.length;

      for (let i = 1; i < size; i++) {
          const key = arr[i];
          let j = i - 1;

          while (j >= 0 && arr[j] > key) {
              arr[j + 1] = arr[j];
              j--;
          }
          arr[j + 1] = key;
      }

      return arr;
  }

  delay(ms: number): Promise<void> {
    return new Promise((resolve) => setTimeout(resolve, ms));
  }
  
  async bubbleSort(arr: number[]): Promise<number[]> {
    console.log("this is arr" + arr.toString());
    const n = arr.length;
    let swapped: boolean;
  
    for (let i = 0; i < n - 1; i++) {
      swapped = false;
  
      for (let j = 0; j < n - 1 - i; j++) {
        if (arr[j] > arr[j + 1]) {
          // Swap elements
          [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
          swapped = true;
          this.step = `Step ${i + 1}: ${arr.join(', ')}`;
        }
      }
  
      // Wait for 1 second
      await this.delay(1000);
  
      // If no two elements were swapped in the inner loop, the array is already sorted
      if (!swapped) {
        break;
      }
    }
    console.log("returning");
    return arr;
  }

  qPartition(arr: number[], low: number, high: number): number {
      const piv = arr[high];
      let i = low - 1;

      for (let j = low; j < high; j++) {
          if (arr[j] < piv) {
              i++;
              this.swap(arr, i, j);
          }
      }

      this.swap(arr, i + 1, high);
      return i + 1;
  }

  quickSort(arr: number[], low: number, high: number): number[] {
      if (low < high) {
          const q_p = this.qPartition(arr, low, high);
          this.quickSort(arr, low, q_p - 1); // QS left
          this.quickSort(arr, q_p + 1, high); // QS right
      }
    
    return arr;
  }

  merge(arr: number[], low: number, middle: number, high: number): number[] {
      let x = 0;
      let y = 0;
      let z = low;

      const size_sub1 = middle - low + 1;
      const size_sub2 = high - middle;

      const sub1 = arr.slice(low, low + size_sub1);
      const sub2 = arr.slice(middle + 1, middle + 1 + size_sub2);

      while (x < size_sub1 && y < size_sub2) {
          if (sub1[x] <= sub2[y]) {
              arr[z] = sub1[x];
              x++;
          } else {
              arr[z] = sub2[y];
              y++;
          }
          z++;
      }

      while (x < size_sub1) {
          arr[z] = sub1[x];
          x++;
          z++;
      }

      while (y < size_sub2) {
          arr[z] = sub2[y];
          y++;
          z++;
      }

      return arr;
  }

  chooseAlgo(message: {arr: any, algo: number}): number[] {
    if(message.arr != ""){
      this.newArr = message.arr.split(",");
      if(message.algo == 1){
        console.log(this.bubbleSort(this.newArr));
      }
    }
    else{
      return [0];
    }

    return[0];

  }
}

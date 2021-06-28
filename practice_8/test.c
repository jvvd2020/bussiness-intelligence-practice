
void shell_sort(int array[], int length){
	int i;
	int j;
	int k;
	int gap;	//gap是分组的步长
	int temp;	//希尔排序是在直接插入排序的基础上实现的,所以仍然需要哨兵
	for(gap=length/2; gap>0; gap=gap/2){// cycle for gap controll
		for(i=0; i<gap; i++){           //cycle for how many sub-sequence 
			for(j=i+gap; j<length; j=j+gap){    //cycle for each sub-sequence select 
                //insert sort start
				if(array[j] < array[j - gap]){
					temp = array[j];	//哨兵
					k = j - gap;
					while(k>=0 && array[k]>temp){
						array[k + gap] = array[k];
						k = k - gap;
					}
					array[k + gap] = temp;
				}
                //insert sort end
			}   
		}
	}
}

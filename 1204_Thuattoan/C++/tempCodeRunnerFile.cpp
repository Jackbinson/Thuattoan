    do {
        //If there's at least 2 elements are swapped, it'll be true
        isSwapped = false;
        //Iterate through the array's element
        for (int i = 0; i < unsortedElements-1;++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i],arr[i+1]);
                isSwapped = true;
            }
        }
        //After iteration, the last element has been sorted, so it'll be ignored in the nmexxt iteration
        --unsortedElements;
    }
    while (isSwapped)
 
    
}
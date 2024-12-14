auto end = high_resolution_clock::now();
    auto start = high_resolution_clock::now();
        // Tính toán thời gian trôi qua
    auto duration = duration_cast<microseconds>(end - start);
    cout << " " << endl;
    cout << "Time taken for the search: " << duration.count() << " microseconds" << endl;
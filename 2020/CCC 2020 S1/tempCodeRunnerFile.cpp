
    for (int i = 0; i < array.size() - 1; ++i){
        cout << array[i][1] - array[i+1][1] << " " << array[i+1][0] - array[i][0] << "\n";
        // cout << abs(array[i][1] - array[i+1][1]) / (array[i+1][0] - array[i][0] ) << "\n";
        max_speed = max(max_speed, (abs(array[i][1] - array[i+1][1]) / (array[i+1][0] - array[i][0] )));
    }

    cout << max_speed;
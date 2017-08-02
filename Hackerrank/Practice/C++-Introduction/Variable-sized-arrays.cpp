    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q, k;
    int * arr[100000];
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        cin >> k;
        arr[i] = new int[k];
        for(int j = 0; j < k; ++j) {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < q; i++) {
        cin >> n >> k;
        cout << arr[n][k] << "\n";
    }
	return 0;
}

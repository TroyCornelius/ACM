    while(cin >> n) {
        int ans = 0;
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        cin >> m;
        for(int i = 0; i < m; i++) scanf("%d", &b[i]);
        sort(a, a + n);
        sort(b, b + m);
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(b[i] % a[j] == 0) res = max(res, b[i] / a[j]);
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(b[i] % a[j] == 0 && b[i] / a[j] == res) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}


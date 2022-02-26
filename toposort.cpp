//Init
    for(int i=1; i<=m; i++) {
        cin>>u>>v;
        ke[u].push_back(v);
        bacin[v]++;
    }
//

void topo() {
    for(int i=1; i<=n; i++) {
        if(bacin[i]==0) q.push(i);
    }

    topo_list.push_back(0);

    while(q.size()) {
        int fr=q.front();
        q.pop();
        topo_list.push_back(fr);
        for(auto i:ke[fr]) {
            bacin[i]--;
            if(bacin[i]==0) q.push(i);
        }
    }

    for(int i=1; i<=n; i++)
        pos[topo_list[i]]=i;
}

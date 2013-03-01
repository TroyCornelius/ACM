#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int NOR = 1;
const int MIX = 2;
const int CUS = 3;

struct Item
{
    string name;
    int num;
    int cost;
    int type;

    Item(const string & name, int cost, int type, int num = 1) :
    name(name), num(num), cost(cost), type(type)
    {
    }
    Item(){}
    const char * c_str()
    {
        static char msg[500];
        sprintf(msg, "Item(%s, num:%d, cost:%d, type:%d)", name.c_str(),
                num, cost, type);
        return msg;
    }
    bool operator < (const Item & t) const {return name<t.name;}
};

map<string, vector<pair<string, int> > > mixture;
map<string, Item> item_getter;

struct Bag
{
    vector<Item> items;
    int money;

    void AddItem(const string & name)
    {
        if (item_getter.find(name) == item_getter.end()) return;
        Item & item = item_getter[name];
        if (item.cost > money) return;
        if (item.type != MIX && items.size() >= 6) return;
      //  printf("Add %s item:%s\n", name.c_str(), item.c_str());
        if (item.type == MIX)
        {
            vector<pair<string, int> > & list = mixture[name];
           // printf("list size=%d\n", list.size());
            for (int i = 0; i < list.size(); ++i)
            {
                if (!Check(list[i].first, list[i].second)) return;
            }
            set<int> del_pos;
            int sum_cost = 0;
            for (int i = 0; i < list.size(); ++i)
            {
                string & t_name = list[i].first;
                int num = list[i].second;
                for(int j=0;j<items.size(); ++j)
                    if(items[j].name==t_name)
                    {
                        del_pos.insert(j);
                        --num;
                        sum_cost += items[j].cost;
                    }
            }
            vector<Item> new_items;
            for(int i=0;i<items.size();++i) if(del_pos.find(i)==del_pos.end())
            {
                new_items.push_back(items[i]);
            }
            new_items.push_back(Item(name, sum_cost + item.cost, MIX));
            items=new_items;
            //  puts("end");
        }
        else if(item.type == CUS)
        {
            if(HasItem(name))
            {
                GetItem(name).num++;
            }
            else items.push_back(item);
        }
        else
        {
            items.push_back(item);
        }
        money -= item.cost;
    }

    void RemoveItem(const string & name)
    {
        if(!HasItem(name)) return;
        vector<Item>::iterator it;
        for(it=items.begin();it!=items.end();++it) if(it->name==name)
        {
            money += it->cost*it->num;
            items.erase(it);
            break;
        }
    }

    bool HasItem(const string & name)
    {
        for(int i=0;i<items.size();++i) if(items[i].name==name) return true;
        return false;
    }
    Item& GetItem(const string & name)
    {
        for(int i=0;i<items.size();++i) if(items[i].name==name) return items[i];
    }
    bool Check(const string & name, int need)
    {
        //printf("check %s, need:%d", name.c_str(), need);
        int cnt = 0;
        for (int j = 0; j < items.size(); ++j) if (items[j].name == name)
            {
                ++cnt;
            }
        if (cnt < need) return false;
        else return true;
    }

    Bag() : money(0)
    {
    }
};

void Init()
{
    mixture.clear();
    item_getter.clear();
}

int main()
{
    int n1;
    int ca = 1;
    while (cin >> n1)
    {
        Init();
        for (int i = 0; i < n1; ++i)
        {
            char name[50];
            int cost;
            scanf("%s%d", name, &cost);
            item_getter.insert(make_pair(name, Item(name, cost, NOR)));
        }
        int n2;
        cin >> n2;
        for (int i = 0; i < n2; ++i)
        {
            char name[50];
            int cost;
            char list[300];
            scanf("%s%d:%[^\n]", name, &cost, list);
            item_getter.insert(make_pair(name, Item(name, cost, MIX)));
            vector<pair<string, int> > & vList = mixture[name];
            string slist = list;
            int pos = 0;
           // printf("list='%s'\n", list);
            if(slist.size()<=1) continue;
            while (true)
            {
                int ed = slist.find(',', pos);
                string sub = slist.substr(pos, ed - pos);
                int num;
                sscanf(sub.c_str(), "%s%d", name, &num);
                vList.push_back(pair<string, int>(name, num));
                //printf("dep: %s %d!!\n", name, num);
                if (ed == string::npos) break;
                else pos = ed + 1;
            }
        }
        int n3;
        cin >> n3;
        for (int i = 0; i < n3; ++i)
        {
            char name[50];
            int cost;
            scanf("%s%d", name, &cost);
            item_getter.insert(make_pair(name, Item(name, cost, CUS)));
        }
        Bag bag;
        int cmd_cnt;
        cin>>cmd_cnt;
        while(cmd_cnt--)
        {
            char op;
            char str[1024];
            scanf("%s", str);
            op = str[0];
            string name(str+1);
            if(name[0]>='0'&&name[0]<='9')
            {
                bag.money += atoi(name.c_str());
            }
            else
            {
                if(op=='-') bag.RemoveItem(name);
                else bag.AddItem(name);
            }
            //printf("money = %d\n", bag.money);
            //printf("%c %s\n", op, name.c_str());
        }
        printf("Case %d:\n", ca++);
        printf("%d\n", bag.money);
        printf("%d\n", bag.items.size());
        sort(bag.items.begin(), bag.items.end());
        for(int i=0;i<bag.items.size();++i)
        {
            printf("%s: %d\n", bag.items[i].name.c_str(), bag.items[i].num);
        }
        puts("");
    }
    return 0;
}


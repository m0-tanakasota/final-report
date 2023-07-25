#include <iostream>
#include<random>
#include<vector>
#include<fstream>
using namespace std;

class firstround {
    int result1;
    int result2;
public:
    void setresult1(int newResult1);
    void setresult2(int newResult2);
    void show();
};

void firstround::setresult1(int newResult1) {
    result1 = newResult1;
}

void firstround::setresult2(int newResult2) {
    result2 = newResult2;
}

void firstround::show() {
    cout << result1 << "対" << result2 << endl;
}

int total(int z1, int z2) {
    int w = (z1 + z2);
    return w;
}

int main()
{
    cout << "サッカーのPK戦を始めます。キッカーは１から3のエリアに蹴りこむことができ、キーパーもランダムで１から５のエリアに向かって動くことができる。\n";
    cout << "プレイヤーはAチームとBチームに分かれてプレーしてしまう\n";
    cout << "Aチームは先行、Bチームは後攻でPK戦はキックオフとなる\n";

    vector<int>count1;
    vector<int>count2;
    vector<int>count12;
    vector<int>count22;

    for (int t = 1;t <= 5;++t) {

        cout << "第" << t << "回戦\n";
        cout << "チームAのキッカー１、1から3エリアのどこに蹴りこむかを決めてください。\n";
        int a;
        a = 0;
        cin >> a;

        vector<int>v1;
        random_device engine;
        uniform_int_distribution<unsigned>dist1(1, 3);
        for (int i = 0;i <= 1;++i) {
            int n = dist1(engine);
            v1.push_back(n);
        }
        cout << "キーパーの選択は\n";
        int n = dist1(engine);
        cout << n << endl;
        {
            if (a == n) {
                cout << "PK失敗" << endl;
                count1.push_back(0);
            }
            else {
                cout << "PK成功！" << endl;
                count1.push_back(1);
                count12.push_back(1);
            }
        }

        cout << "チームBのキッカー１、1から3エリアのどこに蹴りこむかを決めてください。\n";
        int b;
        b = 0;
        cin >> b;
        uniform_int_distribution<unsigned>dist2(1, 3);
        for (int i = 0;i <= 1;++i) {
            int m = dist2(engine);
            v1.push_back(m);
        }
        cout << "キーパーの選択は\n";
        int m = dist2(engine);
        cout << m << endl;
        ofstream datafile("score.txt", ios_base::out);

        if (a != n) {
            if (b != m) {
                cout << "PK成功！" << endl;
                count2.push_back(1);
                count22.push_back(1);
                datafile << 1 << " " << 1 << endl;
                datafile.close();

            }
            else {
                cout << "PK失敗" << endl;
                count2.push_back(0);
                datafile << 1 << " " << 0 << endl;
                datafile.close();

            }
        }

        else {
            if (b == m) {
                cout << "PK失敗" << endl;
                count2.push_back(0);
                datafile << 0 << " " << 0 << endl;
                datafile.close();

            }
            else {
                cout << "PK成功！" << endl;
                count2.push_back(1);
                count22.push_back(1);
                datafile << 0 << " " << 1 << endl;
                datafile.close();
            }
        }

        vector <firstround>dai1;
        ifstream infile("score.txt");
        int result1;
        int result2;
        while (infile >> result1 >> result2) {
            dai1.emplace_back();
            dai1[dai1.size() - 1].setresult1(result1);
            dai1[dai1.size() - 1].setresult2(result2);
        }
        infile.close();

        cout << "第" << t << "回戦の結果は\n";
        for (int y = 0;y < dai1.size();y++) dai1[y].show();

        cout << "今回の決定率は\n";
        if (a != n && b != m) {
            int z1 = 50;
            int z2 = 50;
            int w = total(z1, z2);
            cout << w << "%" << endl;
        }
        else if (a == n && b != m) {
            int z1 = 0;
            int z2 = 50;
            int w = total(z1, z2);
            cout << w << "%" << endl;
        }
        else if (a != n && b == m) {
            int z1 = 50;
            int z2 = 0;
            int w = total(z1, z2);
            cout << w << "%" << endl;
        }
        else if (a == n && b == m) {
            int z1 = 0;
            int z2 = 0;
            int w = total(z1, z2);
            cout << w << "%" << endl;
        }
    }
    //第５回戦終了


    if (count12.size() == count22.size()) {
        for (int s = 5;++s;) {
            cout << "第" << s << "回戦\n";
            cout << "チームAのキッカー１、1から5エリアのどこに蹴りこむかを決めてください。\n";
            int e;
            e = 0;
            cin >> e;
            vector<int>v1;
            random_device engine;
            uniform_int_distribution<unsigned>dist3(1, 3);
            for (int i = 0;i <= 1;++i) {
                int u = dist3(engine);
                v1.push_back(u);
            }
            cout << "キーパーの選択は\n";
            int u = dist3(engine);
            cout << u << endl;

            if (e == u) {
                cout << "PK失敗" << endl;
                count1.push_back(0);
            }
            else {
                cout << "PK成功！" << endl;
                count1.push_back(1);
                count12.push_back(1);
            }

            cout << "チームBのキッカー１、1から5エリアのどこに蹴りこむかを決めてください。\n";
            int f;
            f = 0;
            cin >> f;

            uniform_int_distribution<unsigned>dist4(1, 3);
            for (int i = 0;i <= 1;++i) {
                int m = dist4(engine);
                v1.push_back(m);
            }
            cout << "キーパーの選択は\n";
            int r = dist4(engine);
            cout << r << endl;

            if (e == u) {
                if (f == r) {
                    cout << "PK失敗" << endl;
                    count2.push_back(0);
                    fstream datafile("score.txt", ios_base::out);
                    datafile << 0 << " " << 0 << endl;
                    datafile.close();
                }
                else {
                    cout << "PK成功！" << endl;
                    count2.push_back(1);
                    count22.push_back(1);
                    fstream datafile("score.txt", ios_base::out);
                    datafile << 0 << " " << 1 << endl;
                    datafile.close();

                }
            }

            else if (e != u) {
                if (f != r) {
                    cout << "PK成功！" << endl;
                    count2.push_back(1);
                    count22.push_back(1);
                    fstream datafile("score.txt", ios_base::out);
                    datafile << 1 << " " << 1 << endl;
                    datafile.close();
                }
                else {
                    cout << "PK失敗" << endl;
                    count2.push_back(0);
                    fstream datafile("score.txt", ios_base::out);
                    datafile << 1 << " " << 0 << endl;
                    datafile.close();
                }
            }

            vector <firstround>dai2;
            ifstream infile("score.txt");
            int result1;
            int result2;
            while (infile >> result1 >> result2) {
                dai2.emplace_back();
                dai2[dai2.size() - 1].setresult1(result1);
                dai2[dai2.size() - 1].setresult2(result2);
            }
            infile.close();
            cout << "第" << s << "回戦の結果は\n";
            for (int y = 0;y < dai2.size();y++) dai2[y].show();

            if (e == u) {
                if (f != r) {
                    break;
                }
            }
            if (e != u) {
                if (f == r) {
                    break;
                }
            }
        }
    }
    //６回戦以降終了

    cout << "両チームの各スコアを確認する.\n";
    cout << "1は成功を表し、0は失敗を表すこれを蹴った順番に沿って示す.\n";

    cout << "Aチーム:\n";
    for (auto k = count1.cbegin(); k != count1.end();++k) {
        cout << *k << "｜";
    }

    cout << endl;
    cout << "Bチーム:\n";
    for (auto l = count2.cbegin(); l != count2.end();++l) {
        cout << *l << "｜";
    }
    cout << endl;
    cout << "Aチーム合計：" << count12.size();
    cout << "\n";
    cout << "Bチーム合計：" << count22.size();
    cout << "\n";



    if (count12.size() > count22.size()) {
        cout << "Aチームの勝利！\n";
        cout << "おめでとう！\n";
    }
    else if (count12.size() < count22.size()) {
        cout << "Bチームの勝利！\n";
        cout << "おめでとう！\n";
    }
    cout << "プレーしてくれてありがとう！\n";
    cout << "また遊んでね！\n";
}
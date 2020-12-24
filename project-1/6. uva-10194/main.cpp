#include <bits/stdc++.h>

using namespace std;

struct Team
{
    /* data */
    string name;
    int points;
    int games;
    int wins;
    int ties;
    int loses;
    int goals;
    int goals_against;

    Team()
        : name(""),
          points(0),
          games(0),
          wins(0),
          ties(0),
          loses(0),
          goals(0),
          goals_against(0)
    {
    }

    Team(string n)
    {
        name = n;
        points = games = wins = ties = loses = goals = goals_against = 0;
    }
};

struct CmpByName
{
    /* data */
    bool operator()(Team t1, Team t2)
    {
        return t1.name < t2.name;
    }
};

void main()
{
    int n;
    cin >> n; //tournaments
    vector<Team> teams(31);

    while (n--)
    {
        string tn;
        cin >> tn;
        int teamN;
        cin >> teamN;

        string team_tmp;

        for (int i = 0; i < teamN; i++)
        {
            getline(cin, team_tmp);
            teams[i] = Team(team_tmp);
        }

        sort(teams.begin(), teams.end(), CmpByName());

        string t1, t2;
        int sc1, sc2;

        int g;
        cin >> g;

        for (int i = 0; i < g; i++)
        {
            getline(cin, t1, '#');
            cin >> sc1;
            cin.get();

            cin >> sc2;
            cin.get();
            getline(cin, t2);

            auto it1 = lower_bound(teams.begin(), teams.end(), t1, CmpByName());
            auto it2 = lower_bound(teams.begin(), teams.end(), t2, CmpByName());

            it1->goals += sc1;
            it1->goals_against += sc2;
            it2->goals += sc2;
            it2->goals_against += sc1;
        }
    }
}
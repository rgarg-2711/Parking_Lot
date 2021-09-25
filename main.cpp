#include <bits/stdc++.h>
using namespace std;

class car
{
  public:
    string regno;
  int age;

  car(string num, int ag)
  {
    regno = num;
    age = ag;

  }
};

class Create
{
  public:

    int capacity = 0;
  int curr = 0;
  map<int, car*> slotinfo;

  Create(int cap)
  {
    capacity = cap;
    curr = 0;
    cout << "Created parking of " << cap << " slots" << endl;
  }

  void Park(string num, int ag)
  {
    for (auto m: slotinfo)
    {
      if (m.second->regno == num)
      {
        cout << "Already parked at slot number " << m.first << endl;
        return;
      }
    }

    if (curr == capacity)
    {
      cout << "Parking lot if full";
    }
    else
    {
      for (int i = 1; i <= capacity; i++)
      {
        if (!slotinfo[i])
        {
          curr++;
          slotinfo[i] = new car(num, ag);
          cout << "Car with vehicle registration number \"" << slotinfo[i]->regno << "\" has been parked at slot number " << i << endl;
          break;
        }
      }
    }
  }

  void Leave(int posn)
  {
    if (!slotinfo[posn])
    {
      cout << "Slot already vacant" << endl;
      return;
    }

    cout << "Slot number " << posn << " vacated, the car with vehicle registration number \"" << slotinfo[posn]->regno << "\" left the space, the driver of the car was of age " << slotinfo[posn]->age << endl;
    slotinfo.erase(posn);
    curr--;
  }

  void FindRegNum(int ag)
  {
    int prev = 0;
    for (auto m: slotinfo)
    {
      if (m.second->age == ag)
      {
        if (prev)
        {
          cout << ",";

        }
        else
        {
          prev = 1;
        }

        cout << "\"" << m.second->regno << "\"";
      }
    }

    cout << endl;
  }

  void SlotNums(int ag)
  {
    int prev = 0;
    for (auto m: slotinfo)
    {
      if (m.second->age == ag)
      {
        if (prev)
        {
          cout << ",";

        }
        else
        {
          prev = 1;
        }

        cout << m.first;
      }
    }

    cout << endl;
  }

  void FindSlot(string num)
  {
    int f = 0;
    for (auto m: slotinfo)
    {
      if (m.second->regno == num)
      {
        f = 1;
        cout << m.first << endl;
        break;
      }
    }

    if (!f)
    {
      cout << "This car not present till now!" << endl;
    }
  }
};

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  #endif

  string s;
  vector<string> v;

  //store each command in a vector
  while (getline(cin, s))
  {
    v.push_back(s);
  }

  //if 1st command does not create parking lot
  if (v[0][0] != 'C')
  {
    cout << "there is no space for parking lot!";
    return 0;
  }

  string siz = v[0].substr(19);
  int cap = stoi(siz);

  //if 0 or less no of slots
  if (cap <= 0)
  {
    cout << "Invalid size of parking lot!";
    return 0;
  }

  Create *lot = new Create(cap);

  for (int i = 1; i < v.size(); i++)
  {
    if (v[i][0] == 'P')
    {
      string num = v[i].substr(5, 13);
      int ag = stoi(v[i].substr(30));

      lot->Park(num, ag);
    }
    else if (v[i][0] == 'L')
    {
      int posn = stoi(v[i].substr(6));
      lot->Leave(posn);

    }
    else if (v[i][0] == 'V')
    {
      int ag = stoi(v[i].substr(46));
      lot->FindRegNum(ag);
    }
    else if (v[i][0] == 'S')
    {
      if (v[i][11] == 's')
      {
        int ag = stoi(v[i].substr(31));
        lot->SlotNums(ag);
      }
      else
      {
        string num = v[i].substr(32);
        lot->FindSlot(num);
      }
    }
    else
    {
      cout << "Invalid command";
    }
  }

  return 0;
}
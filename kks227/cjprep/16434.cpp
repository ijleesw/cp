#include "bits/stdc++.h"
using namespace std;

struct Room
{
    long type;
    long atk;
    long hp;
};

bool can_beat(const vector<Room>& rooms, long atk, long hp)
{
    const auto max_hp = hp;
    for (const auto& room : rooms) {
        if (room.type == 1) {
            long my_turn = (room.hp + atk - 1) / atk;
            long mon_turn = (hp + room.atk - 1) / room.atk;

            if (my_turn > mon_turn) {
                return false;
            } else {
                hp -= room.atk * (my_turn - 1);
            }

        } else if (room.type == 2) {
            atk += room.atk;
            hp = min(max_hp, hp + room.hp);

        } else {
            assert(false);
        }

    }
    return true;
}

int main()
{
    long room_cnt, init_atk;
    cin >> room_cnt >> init_atk;

    vector<Room> rooms(room_cnt);
    for (long i = 0; i < room_cnt; ++i) {
        cin >> rooms[i].type >> rooms[i].atk >> rooms[i].hp;
    }

    long l = 1;
    long r = numeric_limits<long>::max() / 2;
    long res = -1;

    while (l <= r) {
        auto m = (l + r) / 2;

        if (can_beat(rooms, init_atk, m)) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    assert(res != -1);

    cout << res << endl;

    return 0;
}
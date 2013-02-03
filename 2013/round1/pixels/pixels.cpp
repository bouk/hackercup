#include <set>
#include <vector>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int W, H, P, Q, N, X, Y, a, b, c, d;

map<int, set<int> > pixels;

void testcase(int t)
{
    pixels.clear();

    cin >> W >> H >> P >> Q >> N >> X >> Y >> a >> b >> c >> d;

    int prevx = X;
    int prevy = Y;
    pixels[X].insert(Y);

        // cerr << prevx << ':' << prevy << endl;
    for (int i = 1; i < N; i++)
    {
        int newx = (prevx * a + prevy * b + 1) % W;
        prevy = (prevx * c + prevy * d + 1) % H;
        prevx = newx;
        pixels[prevx].insert(prevy);
        // cerr << prevx << ':' << prevy << endl;
    }
    // cerr << endl;

    unsigned long long open = 0;

    for (int y = 0; y < H - Q + 1; y++)
    {
        for (int x = 0; x < W - P + 1; x++)
        {
            // Check whether we can place the image
            auto lower_x = pixels.lower_bound(x);
            auto upper_x = pixels.upper_bound(x + P - 1);
            while(lower_x != upper_x)
            {
                // Go through all sets where the x is between x and x + P - 1
                upper_x--;
                auto& x_map = (*upper_x).second;
                auto lower_y = x_map.lower_bound(y);
                auto upper_y = x_map.upper_bound(y + Q - 1);
                if(lower_y != upper_y)
                {
                    // If the image overlaps a dead pixel, you can skip forward to a point where this pixels no longer overlaps (yay)
                    x = (*upper_x).first;
                    goto nextloop;
                }
            }

            open++;
            nextloop:
            continue;
        }
    }

    cout << "Case #" << t << ": " << open << endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        testcase(t);
    }
    return 0;
}
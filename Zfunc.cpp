#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ZFinder 
{
public:
  ZFinder(std::string text, std::string pattern)
      : _text(text), _pattern(pattern), _joined(_pattern + "$" + _text)
      {
          z = computeZ();
      };

  int compareParts(const std::string &s, const int first, const int second) {
    int cnt = 0; 
    while (first + cnt < s.size() && second + cnt < s.size() &&
           s[first + cnt] == s[second + cnt])
        cnt++;

    return cnt;
  }

  std::vector<int> computeZ() 
  {
    std::vector<int> z(_joined.size(), 0);

    int L = 0, R = 0;

    for (int k = 1; k < _joined.size(); k++) {
      if (k > R) 
      {
        int cnt = compareParts(_joined, k, 0);
        z[k] = cnt;
        L = k;
        R = k + cnt - 1;
      } else 
      {
        if (z[k - L] < R - k + 1) {
          z[k] = z[k - L];
        } else {
          int cnt = compareParts(_joined, R + 1, R - L + 1);
          z[k] = (R - k + 1) + cnt;
          L = k;
          R = R + z[k] - 1;
        }
      }
    }
    return z;
  }

  int find() 
  {
    for (int i = _cur; i < _joined.size(); i++) {
      if (z[i] == _pattern.size()) 
      {
        if (i > _cur)
        {
            _cur = i;
            return ( _cur - _pattern.size() - 1 );
        }   
      }
    }
    return -1;
  }

  int freq()
  {
    return count(z.begin(), z.end(), _pattern.size());
  }

  int last_occur()
  {
      std::vector<int> z_vec = computeZ();
      for (auto i =  z_vec.size() + 1; i > _pattern.size(); i--)
      {
          if (z_vec[i] == _pattern.size())
            return (i - (_pattern.size() + 1));
      }
      return -1;
  }

private:
  std::string _text;
  std::string _pattern;
  std::string _joined;
  std::vector<int> z;
  int _cur = 0;
};

int main() {
    std::string text = "If a dog chews shoes, whose shoes does he choose?";

    std::string pattern = "oes";

    ZFinder zFinder(text, pattern);

    // cout << zFinder.freq();

    int pos = zFinder.find();
    while (pos != -1) 
    {
        std::cout << pos << std::endl; // 17 30 35
        pos = zFinder.find();
    }
    return 0;
}

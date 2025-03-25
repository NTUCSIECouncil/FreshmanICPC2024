#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char s[] = "WelcomeToFreshmanICPC";
    for (char *p = s, i = 0; i < strlen(s); ++i, ++p) {
      *(p) = tolower(*(p));
    }
    cout << s << endl;
    return 0;
}

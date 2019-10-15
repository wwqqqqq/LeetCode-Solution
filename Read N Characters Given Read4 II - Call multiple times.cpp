// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    string buffer;
    int read(char *buf, int n) {
        char * p = buf;
        int count = 0;
        if(buffer.size() >= n) {
            for(int i = 0; i < n; i++)
                buf[i] = buffer[i];
            buffer.erase(buffer.begin(), buffer.begin()+n);
            return n;
        }
        else if(buffer.size() > 0) {
            n -= buffer.size();
            for(int i = 0; i < buffer.size(); i++, p++) {
                *p = buffer[i];
                count++;
            }
            buffer.erase(buffer.begin(), buffer.end());
        }
        while(n > 0) {
            int len = read4(p);
            p += len;
            n -= len;
            count += len;
            if(len < 4)
                break;
        }
        if(n < 0) {
            p -= 4;
            for(int i = 4+n;i < 4; i++) {
                buffer.append(1, p[i]);
                p[i] = '\0';
                count--;
            }
        }
        return count;
    }
};
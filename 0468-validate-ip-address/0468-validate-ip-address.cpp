class Solution {
public:
    string validIPAddress(string queryIP) {
        bool hasDot = false;
        bool type = false;

        int idx = 0;
        while (idx < queryIP.size()) {
            if (queryIP[idx] == '.') {
                type = true;
                hasDot = true;
                break;
            } else if (queryIP[idx] == ':') {
                hasDot = true;
                break;
            }
            idx++;
        }

        if (!hasDot) {
            return "Neither";
        }

        if (type == true) {
            // IPv4 Address
            if (queryIP.size() > 15) {
                return "Neither";
            }

            int nrDots = 0;
            int nr = 0;
            for (int i = 0; i < queryIP.size(); i++) {
                if (queryIP[i] != '.' && (queryIP[i] < '0' || queryIP[i] > '9')) {
                    return "Neither";
                } else if (queryIP[i] != '.') {
                    if (queryIP[i] == '0' && i == queryIP.size() - 1) {
                        return "IPv4";
                    } else if (queryIP[i] == '0') {
                        if (i == 0 && queryIP[i + 1] != '.') {
                            return "Neither";
                        } else if (i != 0 && queryIP[i - 1] == '.' && (queryIP[i + 1] != '.')) {
                            return "Neither";
                        }
                    }

                    nr = nr * 10 + queryIP[i] - '0';

                    if (i == queryIP.size() - 1 && (nr > 255 || nrDots != 3)) {
                        return "Neither";
                    }
                } else if (queryIP[i] == '.') {
                    if (nr > 255 || i == queryIP.size() - 1 || queryIP[i - 1] == '.') {
                        return "Neither";
                    }

                    nr = 0;
                    nrDots++;

                    if (nrDots > 3) {
                        return "Neither";
                    }
                }
            }


            return "IPv4";
        } else {
            if (queryIP.size() > 39 || queryIP[0] == ':' || queryIP[queryIP.size() - 1] == ':') {
                return "Neither";
            }

            int nrDots = 0;
            string s = "";

            for (int i = 0; i < queryIP.size(); i++) {
                if (queryIP[i] != ':') {
                    if ((queryIP[i] >= '0' && queryIP[i] <= '9') ||
                        (queryIP[i] >= 'a' && queryIP[i] <= 'f') ||
                        (queryIP[i] >= 'A' && queryIP[i] <= 'F')) {
                            s += queryIP[i];

                            if (s.size() > 4) {
                                return "Neither";
                            }
                        } else {
                            return "Neither";
                        }
                } else {
                    if (queryIP[i - 1] == ':') {
                        return "Neither";
                    }

                    nrDots++;
                    s = "";

                    if (nrDots > 7) {
                        return "Neither";
                    }
                }
            }

            return "IPv6";
        }

        return "";
    }
};
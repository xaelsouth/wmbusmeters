/*
 Copyright (C) 2017-2019 Fredrik Öhrström

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include"cmdline.h"
#include"meters.h"

using namespace std;

struct Printer {
    Printer(bool json,
            bool fields,
            char separator,
            bool meterfiles, string &meterfiles_dir,
            bool use_logfile, string &logfile,
            vector<string> shell_cmdlines,
            bool overwrite);

    void print(Meter *meter);

    private:

    bool json_, fields_;
    bool use_meterfiles_;
    string meterfiles_dir_;
    bool use_logfile_;
    string logfile_;
    char separator_;
    vector<string> shell_cmdlines_;
    bool overwrite_;

    void printShells(Meter *meter, vector<string> &envs);
    void printFiles(Meter *meter, string &human_readable, string &fields, string &json);

};
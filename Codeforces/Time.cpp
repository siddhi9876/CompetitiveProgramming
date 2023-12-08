
#include <chrono>
#include <ctime>
#include <iostream>
using namespace std;
using namespace std::chrono;

string getTimeStr(){
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    std::string s(30, '\0');
    std::strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S.%03d", std::localtime(&now));
    return s;
}
int main(){

//    FILETIME  tm = CTime::GetCurrentTime();
// 		CString cs;
// 		cs.Format("%02d/%02d/%d", tm.GetDay(), tm.GetMonth(), tm.GetYear());

    cout<<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count().T<< endl;
}

// std::chrono::time_point<std::chrono::system_clock> startTime, endTime;
// 	startTime = std::chrono::system_clock::now();
// 		endTime = std::chrono::system_clock::now();
// 		std::chrono::duration<double> elapsed_seconds = endTime - startTime;
// 		cout << (elapsed_seconds.count() * 1000) << endl;

// auto startTime = std::chrono::high_resolution_clock::now();
	
// 		auto endTime = std::chrono::high_resolution_clock::now();
// 		return (endTime - startTime).count();
// 	}

// static std::chrono::steady_clock::time_point ProcessStartTime = std::chrono::steady_clock::now();

// std::chrono::milliseconds dmsecSinceLastRecoverySave = std::chrono::duration_cast<std::chrono::milliseconds>(tsCurrentTime - pDOCCB->m_lastAutoSaveTime);
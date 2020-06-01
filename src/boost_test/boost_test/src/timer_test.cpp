
#include <iostream>
#include <boost/timer.hpp>
using namespace std;
using namespace boost;


#include <boost/static_assert.hpp>

template<int N = 2>
class new_progress_timer:public boost::timer
{
public:
	new_progress_timer(std::ostream& os = std::cout): m_os(os){
		BOOST_STATIC_ASSERT(N >= 0 && N <= 10);
	}
	~new_progress_timer(void){
		try{
			std::istream::fmtflags old_flags = m_os.setf( std::istream::fixed, std::istream::floatfield );
			std::streamsize old_prec = m_os.precision( N );
			m_os << "new progress timer: " << elapsed() << " s\n" << endl;
			m_os.flags( old_flags );
			m_os.precision( old_prec );
		}
		catch (...){

		}
	}

private:
	std::ostream & m_os;
};

#include <boost/progress.hpp>
#include <vector>
#include <fstream>

class progress_display_test
{
public:
	progress_display_test(){
		vector<string> v(100);
		ofstream fs("test.txt");
		progress_display pd(v.size());					// 构造函数，传入进度总数

		vector<string>::iterator pos;
		for (pos = v.begin(); pos != v.end(); ++pos){	// 遍历迭代，处理字符串，写文件
			fs << *pos << endl;
			++pd;										// 更新进度
		}
		fs.close();
	}
};

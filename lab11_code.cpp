#include <iostream>
using namespace std;

#define Valid_REQ 1
#define INVALID_REQ 0

#define REQ_gdesign  1
#define REQ_vid  2
#define REQ_cwrite  3

class Freelancer
{
	protected:
	int m_nReqtype;
	Freelancer *pnext;
	public:
		Freelancer(int nReqtype)
		{
			m_nReqtype = nReqtype;
		}
		void SetNextSlot(Freelancer* pnext )
		{
			this ->	pnext = pnext;
		}
		virtual int Run(int request){
			return INVALID_REQ;
		}
		
};

class GraphicDesign : public Freelancer{
	public:
		GraphicDesign():Freelancer(REQ_gdesign)
		{
			pnext=NULL;
		}
		virtual int Run(int request){
			if (m_nReqtype == request)
			{
				cout<<endl<<"In right slot";
				cout<<endl<<"Welcome to the Graphic Design class";
				return Valid_REQ;
			}
			else
			{
				cout<<endl<<"moving to next slot";
				return pnext->Run(request);
			}
		}
		
};

class VideoEditing : public Freelancer{
	public:
		VideoEditing():Freelancer(REQ_vid)
		{
			pnext=NULL;
		}
		virtual int Run(int request){
			if (m_nReqtype == request)
			{
				cout<<endl<<"In right slot";
				cout<<endl<<"Welcome to the Video Editing class";
				return Valid_REQ;
			}
			else
			{
				cout<<endl<<"moving to next slot";
				return pnext->Run(request);
			}
		}
		
};

class ContentWriting : public Freelancer{
	public:
		ContentWriting():Freelancer(REQ_cwrite)
		{
			pnext=NULL;
		}
		virtual int Run(int request){
			if (m_nReqtype == request)
			{
				cout<<endl<<"In right slot";
				cout<<endl<<"Welcome to the Content Writing class";
				return Valid_REQ;
			}
			else
			{
				cout<<endl<<"moving to next slot";
				return pnext->Run(request);
			}
		}
		
};

int main()
{
	Freelancer* p1 = new GraphicDesign();
	Freelancer* p2 = new VideoEditing();
	Freelancer* p3 = new ContentWriting();
	
	p1 -> SetNextSlot(p2);
	p2 -> SetNextSlot(p3);
	
	p1 -> Run(2);
	
	return 0;
	
}

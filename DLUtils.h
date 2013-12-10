#ifndef DLUtils_h
#define DLUtils_h

class ScrollingText
{
	public:
		ScrollingText()
		{
			text = NULL;
			dir = 1;
			cursorPos = 0;
			windowSize = 16;
			charsPerSec = 1;
		}
		void Update(String text,int cursorPos, float charsPerSec, unsigned int windowSize)
		{
			
			this->length = text.length();
			
			this->minPos = 0;
			
			this->maxPos = length - windowSize;
			if(this->maxPos < 0)
			{
				this->maxPos = 0;
			}
			
			this->windowSize = windowSize;
			this->charsPerSec = charsPerSec;
			
			
			this->text=text;
			
			this->cursorPos = cursorPos;
			this->lastTime = 0;
		}
		void Update(String text)
		{
			Update(text,this->cursorPos,this->charsPerSec,this->windowSize);
		}
		String GetString()
		{
			
			cursorPos += dir*(float)(millis()-lastTime)*charsPerSec/1000;
			
			
			lastTime = millis();
			if(cursorPos > maxPos)
			{
				dir = -1;
				cursorPos = maxPos;
			}
			if(cursorPos < minPos)
			{
				dir = 1;
				cursorPos = minPos;
			}
			
			return this->text.substring(cursorPos);
			
		}
	private:
		int dir;
		float cursorPos;
		int minPos,maxPos;
		unsigned int length,windowSize;
		long lastTime;
		String text;
		float charsPerSec;
};

#endif
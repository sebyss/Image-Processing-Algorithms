#include"TraceBoundaryPoints.h"
TraceBoundaryPoints::TraceBoundaryPoints()
{
	// Do nothing
}
TraceBoundaryPoints::~TraceBoundaryPoints()
{
	//Do nothing
}
/*
* Description - Get the continous boundary points
* Parameters
* InputImage	- Input image
* Width_i		- Width of the image
* Height_i		- Height of Image
* BoundaryPoints - Vector of boundary points (output)
*/
void TraceBoundaryPoints::GetContinousBoundaryPoints(unsigned char* InputImage, int Width_i, int Height_i,
	std::vector<Point2D>& BoundaryPoints)
{
	int nImageSize = Width_i * Height_i;
	if (NULL != InputImage)
	{
		int Offset[8][2] = {
			{ -1, -1 },       //  +----------+----------+----------+
			{ 0, -1 },		  //  |          |          |          |
			{ 1, -1 },        //  |(x-1,y-1) | (x,y-1)  |(x+1,y-1) |
			{ 1, 0 },         //  +----------+----------+----------+
			{ 1, 1 },         //  |(x-1,y)   |  (x,y)   |(x+1,y)   |
			{ 0, 1 },         //  |          |          |          |
			{ -1, 1 },        //  +----------+----------+----------+
			{ -1, 0 }         //  |          | (x,y+1)  |(x+1,y+1) |
		};                    //  |(x-1,y+1) |          |          |
							  //  +----------+----------+----------+
		const int NEIGHBOR_COUNT = 8;
		Point2D BoundaryPixelCord;
		Point2D BoundaryStartingPixelCord;
		Point2D BacktrackedPixelCord;
		int BackTrackedPixelOffset[1][2] = { { 0,0 } };
		bool bIsBoundaryFound = false;
		bool bIsStartingBoundaryPixelFound = false;
		for (int Idx = 0; Idx < nImageSize; ++Idx) // getting the starting pixel of boundary
		{
			if (0 != InputImage[Idx])
			{
				BoundaryPixelCord.X = Idx % Width_i;
				BoundaryPixelCord.Y = Idx / Width_i;
				BoundaryStartingPixelCord = BoundaryPixelCord;
				BacktrackedPixelCord.X = (Idx - 1) % Width_i;
				BacktrackedPixelCord.Y = (Idx - 1) / Width_i;
				BackTrackedPixelOffset[0][0] = BacktrackedPixelCord.X - BoundaryPixelCord.X;
				BackTrackedPixelOffset[0][1] = BacktrackedPixelCord.Y - BoundaryPixelCord.Y;
				BoundaryPoints.push_back(BoundaryPixelCord);
				bIsStartingBoundaryPixelFound = true;
				break;
			}
		}
		Point2D CurrentBoundaryCheckingPixelCord;
		Point2D PrevBoundaryCheckingPixxelCord;
		if (!bIsStartingBoundaryPixelFound)
		{
			BoundaryPoints.pop_back();
		}
		while (true && bIsStartingBoundaryPixelFound)
		{
			int CurrentBackTrackedPixelOffsetInd = -1;
			for (int Ind = 0; Ind < NEIGHBOR_COUNT; ++Ind)
			{
				if (BackTrackedPixelOffset[0][0] == Offset[Ind][0] &&
					BackTrackedPixelOffset[0][1] == Offset[Ind][1])
				{
					CurrentBackTrackedPixelOffsetInd = Ind;// Finding the bracktracked pixel's offset index
					break;
				}
			}
			int Loop = 0;
			while (Loop < (NEIGHBOR_COUNT - 1) && CurrentBackTrackedPixelOffsetInd != -1)
			{
				int OffsetIndex = (CurrentBackTrackedPixelOffsetInd + 1) % NEIGHBOR_COUNT;
				CurrentBoundaryCheckingPixelCord.X = BoundaryPixelCord.X + Offset[OffsetIndex][0];
				CurrentBoundaryCheckingPixelCord.Y = BoundaryPixelCord.Y + Offset[OffsetIndex][1];
				int ImageIndex = CurrentBoundaryCheckingPixelCord.Y * Width_i + CurrentBoundaryCheckingPixelCord.X;
				if (0 != InputImage[ImageIndex])// finding the next boundary pixel
				{
					BoundaryPixelCord = CurrentBoundaryCheckingPixelCord;
					BacktrackedPixelCord = PrevBoundaryCheckingPixxelCord;
					BackTrackedPixelOffset[0][0] = BacktrackedPixelCord.X - BoundaryPixelCord.X;
					BackTrackedPixelOffset[0][1] = BacktrackedPixelCord.Y - BoundaryPixelCord.Y;
					BoundaryPoints.push_back(BoundaryPixelCord);
					break;
				}
				PrevBoundaryCheckingPixxelCord = CurrentBoundaryCheckingPixelCord;
				CurrentBackTrackedPixelOffsetInd += 1;
				Loop++;
			}
			if (BoundaryPixelCord.X == BoundaryStartingPixelCord.X &&
				BoundaryPixelCord.Y == BoundaryStartingPixelCord.Y) // if the current pixel = starting pixel
			{
				BoundaryPoints.pop_back();
				bIsBoundaryFound = true;
				break;
			}
		}
		if (!bIsBoundaryFound) // If there is no connected boundary clear the list
		{
			BoundaryPoints.clear();
		}
	}
}

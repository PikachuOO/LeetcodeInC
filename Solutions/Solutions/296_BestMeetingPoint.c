/*A group of two or more people wants to meet and minimize the total travel distance. 
You are given a 2D grid of values 0 or 1, 
where each 1 marks the home of someone in the group. 
The distance is calculated using Manhattan Distance, 
where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, 
as the total travel distance of 2+2+2=6 is minimal. So return 6.

Hint:

Try to solve it in one dimension first. How can this solution apply to the two dimension case?
*/
#include "common.h"
typedef struct _point
{
	int x;
	int y;
} point_t;

typedef struct _rect
{
	int left;
	int top;
	int right;
	int bottom;
} rect_t;

typedef struct _testcase
{
	int p1_idx;
	int p2_idx;
} testcase_t;


static point_t people[10];
static testcase_t test_case[10];
static rect_t rect[10];
static int grect_cnt;
static rect_t final_rect;

static int matrix[3][5] = 
{
	{1,0,0,0,1},
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0 }
};

int FindAllPeople(int row, int col)
{
	int r, c;
	int people_cnt = 0;

	// find all 1s in matrix
	for (r = 0; r < row; r++)
	{
		for (c = 0; c < col; c++)
		{
			if (matrix[r][c])
			{
				people[people_cnt].x = c;
				people[people_cnt].y = r;
				people_cnt++;
			}
		}
	}
	return people_cnt;
}
int GenerateTest(int count)
{
	int test_case_cnt = 0;
	int i, j;
	for (i = 0; i < count; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			test_case[test_case_cnt].p1_idx = i;
			test_case[test_case_cnt].p2_idx = j;
			test_case_cnt++;
		}
	}
	return test_case_cnt;
}

void GenerateDisRect(int idx1, int idx2)
{
	int left  = MIN(people[idx1].x, people[idx2].x);
	int top   = MIN(people[idx1].y, people[idx2].y);
	int right = MAX(people[idx1].x, people[idx2].x);
	int bottom= MAX(people[idx1].y, people[idx2].y);
	rect[grect_cnt].left = left;
	rect[grect_cnt].right = right;
	rect[grect_cnt].top = top;
	rect[grect_cnt].bottom = bottom;
	grect_cnt++;
}
void FindMinRect()
{
	int i;
	final_rect.left = rect[0].left;
	final_rect.right = rect[0].right;
	final_rect.top = rect[0].top;
	final_rect.bottom = rect[0].bottom;

	for (i = 1; i < grect_cnt; i++)
	{
		final_rect.left = MIN(final_rect.left, rect[i].left);
		final_rect.right = MIN(final_rect.right, rect[i].right);
		final_rect.top = MIN(final_rect.top, rect[i].top);
		final_rect.left = MIN(final_rect.bottom, rect[i].bottom);
	}
}
void FindBestMeetingPoint(int row, int col)
{
	int people_cnt;
	int test_cnt;
	int i;
	people_cnt = FindAllPeople(row, col);
	test_cnt   = GenerateTest(people_cnt);

	for (i = 0; i < test_cnt; i++)
	{
		GenerateDisRect(test_case[i].p1_idx, test_case[i].p2_idx);
	}
	FindMinRect();
}


///------------------------------------------------------------------------

#define ROW 3
#define COL 5
#define ABS(x)  (((x)<0)?-(x):(x))
int x_array[3];
int y_array[3];

extern int compare(const void *a, const void *b);

int FindBestMeetingPointII(int row, int col)
{
	int r, c, i;
	int count = 0;
	int distance = 0;
	int median_x, median_y;

	// find all 1s in matrix
	for (r = 0; r < row; r++)
	{
		for (c = 0; c < col; c++)
		{
			if (matrix[r][c])
			{
				x_array[count] = r;
				y_array[count] = c;
				count++;
			}
		}
	}

	qsort(x_array, 3, sizeof(int), compare);
	qsort(y_array, 3, sizeof(int), compare);

	median_x = x_array[3/2];
	median_y = y_array[3/2]; 

	for (i = 0; i < 3; i++)
		distance += ABS(x_array[i] - median_x);
	for (i = 0; i < 3; i++)
		distance += ABS(y_array[i] - median_y);
	return distance;
}

void test_296()
{
	FindBestMeetingPointII(3, 5);
}
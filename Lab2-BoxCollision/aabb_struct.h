#ifndef aabb_struct
#define aabb_struct

struct AABB
{
	int top,left, right, bottom;


};

struct Point
{
	int x;
	int y;
};
AABB construct(int top_p, int left_p, int bottom_p, int right_p);
bool contain (AABB boxe, int x, int y);
bool contain (AABB boxe, Point point);
bool intersect (AABB boxe_1, AABB boxe_2);
bool may_collide(AABB box_ob, AABB box_fr, AABB box_to);
int min (int a, int b);
int max (int a, int b);
AABB min_bounding_box ( AABB box_1, AABB box_2 );
bool may_collide(AABB box_ob, AABB box_fr, AABB box_to);

bool collision_point(AABB box_ob, AABB box_fr, AABB box_to, Point & pt);


#endif

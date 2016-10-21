#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "aabb_struct.h"

using namespace std;



bool contain (AABB boxe, int x, int y){
 /*Checking if the point is in the box*/
	if ((x >= boxe.left && x <= boxe.right)
	 		&& (y >= boxe.top && y <= boxe.bottom )) {
			return true;
	}
	return false;
}

bool contain (AABB boxe, Point point){
			/*simple use of the contain function */
			return contain(boxe, point.x, point.y);
}


bool intersect (AABB boxe_1, AABB boxe_2){

			/*loop on the top line */
			for (int i = boxe_1.left; i <= boxe_1.right; i++) {
				if (contain(boxe_2,i,boxe_1.top)
						|| contain(boxe_2,i ,boxe_1.bottom)	) {
						return true;
				}
			}
			for (int i = boxe_2.left; i <= boxe_2.right; i++) {
				if (contain(boxe_1,i,boxe_2.top)
						|| contain(boxe_1,i ,boxe_2.bottom)	) {
						return true;
				}
			}
			return false;
}


/*minimum of 2 values*/
int min (int a, int b){
	if ( a <= b) {
			return a;
	}
	return b;
}

/*Maximum of 2 values */
int max(int a, int b){
	if ( a >= b) {
		return a;
	}
	return b;
}



AABB min_bounding_box ( AABB box_1, AABB box_2 ){
		AABB box_3=construct(0,0,0,0);
  /*We need to find the Maximum (righ and bottom)  and the minimum (left and top)*/
		box_3.top = min( box_1.top, box_2.top );
		box_3.left = min( box_1.left, box_2.left );
		box_3.right = max( box_1.right, box_2.right );
		box_3.bottom = max( box_1.bottom, box_2.bottom );

		return box_3;
}


/* simple check if the box_ob is in the min_bounding_box of box_fr and box_to*/
bool may_collide(AABB box_ob, AABB box_fr, AABB box_to){
	AABB box_collision=construct(0,0,0,0);
	box_collision=min_bounding_box( box_fr, box_to);

	return  intersect( box_collision, box_ob );

}

bool collision_point(AABB box_ob, AABB box_fr, AABB box_to, Point & pt){
  float a;
	a = ( box_to.top - box_fr.top ) / ( box_to.left - box_fr.left );

	while ((box_fr.bottom <= box_to.bottom) || (box_fr.bottom != box_ob.bottom )
	       || (box_fr.right != box_ob.right)) {
					 box_fr.top= ( a * box_fr.left) - ( a * box_to.left);
					 box_fr.bottom = box_fr.top +  ( box_to.bottom - box_to.top );
					 box_fr.right = box_fr.left + ( box_to.right - box_to.left );

					 if ( box_fr.bottom >= box_ob.bottom ) {
					 		if (intersect(box_fr,box_ob)) {
								pt.y = box_fr.bottom;
								pt.x = box_fr.right;
								return true;
					 		}
				 }
	   return true;

	 }
	 return false;
 }


/*constructor of the structure*/
 AABB construct(int top_p, int left_p, int bottom_p, int right_p){
	 AABB box;
	 if (top_p>bottom_p)
	 {
		 box.top=bottom_p;
		 box.bottom=top_p;
	 }
	 else
	 {
		 box.top=top_p;
		 box.bottom=bottom_p;
	 }
	 if (left_p>right_p)
	 {
		 box.left=right_p;
		 box.right=left_p;
	 }
	 else
	 {
		 box.left=left_p;
		 box.right=right_p;
	 }
	 return box;
 }

#include "comment.h"


Comment::Comment(int comment_id, int bike_id, string comment, time_t date):
    comment_id(comment_id),
    bike_id(bike_id),
    comment(comment),
    date(date)
{

}

time_t Comment::getDate() const {
    return date;
}

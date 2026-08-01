# Write your MySQL query statement below
SELECT author_id AS id FROM Views WHERE author_id = viewer_id GROUP BY AUTHOR_ID ORDER BY author_id;
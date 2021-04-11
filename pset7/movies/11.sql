SELECT title FROM movies
JOIN ratings ON ratings.movie_id = movies.id
JOIN stars ON stars.movie_id = ratings.movie_id
JOIN people ON people.id = stars.person_id
WHERE name LIKE "Chadwick Boseman" ORDER BY rating DESC LIMIT 5;
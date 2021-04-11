SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE name LIKE "Johnny Depp"
INTERSECT
SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE name LIKE "Helena Bonham Carter";
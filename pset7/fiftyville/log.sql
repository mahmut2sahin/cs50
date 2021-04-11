-- Keep a log of any SQL queries you execute as you solve the mystery.

-- All you know is that the theft took place on July 28, 2020 and that it took place on Chamberlin Street.

-- Finding the scene report that the exact time and place
SELECT * FROM crime_scene_reports
WHERE street = "Chamberlin Street" AND month = 7 AND day = 28;


-- 3 interviews that mention courthouse(courthouse is said at crime scene report)
SELECT * FROM interviews
WHERE day = 28 AND month = 7 AND year = 2020 AND transcript LIKE "%courthouse%";


-- People who left the courthouse at that time
SELECT name, phone_number, passport_number, people.license_plate FROM courthouse_security_logs
JOIN people ON people.license_plate = courthouse_security_logs.license_plate
WHERE day = 28 AND activity LIKE "exit"
AND hour = 10 AND minute > 15 AND minute <= 26;


-- People who used the atm earlier that morning
SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE day = 28 AND atm_location LIKE "Fifer Street" AND transaction_type LIKE "withdraw";


--Finding the earliest flight's id and its passengers
SELECT DISTINCT flights.id, flights.destination_airport_id FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
JOIN airports ON airports.id = flights.origin_airport_id
WHERE day = 29 ORDER BY hour ASC, minute ASC LIMIT 1;


--Finding the passengers of that flight and its destination city
SELECT name, city, full_name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
JOIN airports ON airports.id = flights.destination_airport_id
WHERE day = 29 AND flights.destination_airport_id = 4;


-- phone calls that matches with decriptions
SELECT name,  FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE duration < 60 AND day = 28;


-- Finding Ernest's accomplice
SELECT name FROM people
JOIN phone_calls ON phone_calls.receiver = people.phone_number
WHERE duration < 60 AND day = 28 AND phone_calls.caller LIKE "(367) 555-5533";
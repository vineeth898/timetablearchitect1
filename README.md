<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background-color: #f7f7f7;
            color: #333;
            margin: 0;
            padding: 20px;
        }

        h1 {
            color: #004080;
        }

        h2, h3 {
            color: #0066cc;
        }

        table {
            border-collapse: collapse;
            width: 100%;
            margin-top: 20px;
        }

        th, td {
            border: 1px solid #dddddd;
            text-align: left;
            padding: 12px;
        }

        th {
            background-color: #f2f2f2;
        }

        ul {
            margin-top: 10px;
        }

        p {
            color: #666;
        }

        footer {
            margin-top: 20px;
            text-align: center;
            color: #888;
        }
    </style>
    <title>TimeTable Architect</title>
</head>

<body>

    <h1>TimeTable Architect</h1>
    <p>Created by Vineeth Rao and Shreya Prasad</p>

    <section>
        <h2>C++ Class: room</h2>

        <table>
            <tr>
                <th>Data Member</th>
                <th>Data Type</th>
                <th>Purpose</th>
            </tr>
            <tr>
                <td>name</td>
                <td>string</td>
                <td>Represents the name of the room.</td>
            </tr>
            <tr>
                <td>capacity</td>
                <td>int</td>
                <td>Indicates the capacity or seating capacity of the room.</td>
            </tr>
            <tr>
                <td>labOrNot</td>
                <td>bool</td>
                <td>A boolean flag (true or false) indicating whether the room is a laboratory (true for occupied, false for free).</td>
            </tr>
            <tr>
                <td>building</td>
                <td>string</td>
                <td>Represents the building where the room is located.</td>
            </tr>
            <tr>
                <td>timeTable</td>
                <td>bool[days][periods]</td>
                <td>A 2D array representing the availability of the room over a timetable. false indicates the room is free, and true indicates it is occupied.</td>
            </tr>
            <tr>
                <td>timeTableName</td>
                <td>int[days][periods]</td>
                <td>A 2D array representing what class the room is holding when occupied. Changes are done programmatically, not taken from the user.</td>
            </tr>
        </table>

        <h3>Member Functions:</h3>
        <ul>
            <li><code>readData(string inp) - bool</code>: Reads data from the input string and possibly modifies the object's data members accordingly. Returns a boolean indicating the success of the operation.</li>
            <li><code>convertToString() - string</code>: Converts the object's data into a string format.</li>
            <li><code>room()</code>: Default constructor that initializes the <code>timeTableName</code> 2D array, setting all values to 0.</li>
        </ul>
    </section>

    <section>
        <h2>C++ Class: subject</h2>

        <table>
            <tr>
                <th>Data Member</th>
                <th>Data Type</th>
                <th>Purpose</th>
            </tr>
            <tr>
                <td>name</td>
                <td>string</td>
                <td>Represents the name of the subject.</td>
            </tr>
            <tr>
                <td>elective</td>
                <td>string</td>
                <td>Indicates whether the subject is an elective. "0" if not an elective, otherwise the name of the elective.</td>
            </tr>
            <tr>
                <td>lab</td>
                <td>bool</td>
                <td>Indicates whether the subject has a laboratory component (true for lab, false otherwise).</td>
            </tr>
            <tr>
                <td>credits</td>
                <td>int</td>
                <td>Represents the number of credits associated with the subject.</td>
            </tr>
            <tr>
                <td>hoursPerCredit</td>
                <td>int</td>
                <td>Specifies the number of hours per credit for the subject.</td>
            </tr>
            <tr>
                <td>bFactor</td>
                <td>unsigned short int</td>
                <td>A factor associated with how much the subject exhausts the mind.</td>
            </tr>
            <tr>
                <td>rooms</td>
                <td>string*</td>
                <td>A pointer to an array of strings representing rooms associated with the subject.</td>
            </tr>
            <tr>
                <td>noRooms</td>
                <td>unsigned short int</td>
                <td>Indicates the number of rooms associated with the subject.</td>
            </tr>
        </table>

        <h3>Member Functions:</h3>
        <ul>
            <li><code>readData(string inp) - bool</code>: Reads data from the input string and possibly modifies the object's data members accordingly. Returns a boolean indicating the success of the operation.</li>
            <li><code>convertToString() - string</code>: Converts the object's data into a string format.</li>
            <li><code>subject()</code>: Default constructor that initializes <code>credits</code>, <code>hoursPerCredit</code>, and <code>bFactor</code> to 0.</li>
        </ul>
    </section>

    <section>
        <h2>C++ Class: teacher</h2>

        <table>
            <tr>
                <th>Data Member</th>
                <th>Data Type</th>
                <th>Purpose</th>
            </tr>
            <tr>
                <td>name</td>
                <td>string</td>
                <td>Represents the name of the teacher.</td>
            </tr>
            <tr>
                <td>branch</td>
                <td>string</td>
                <td>Indicates the branch of the teacher.</td>
            </tr>
            <tr>
                <td>timeTable</td>
                <td>bool[days][periods]</td>
                <td>A 2D array representing the availability of the teacher over a timetable. 0 indicates the teacher is free, and 1 indicates the teacher is occupied.</td>
            </tr>
            <tr>
                <td>timeTableName</td>
                <td>unsigned int[days][periods]</td>
                <td>A 2D array representing what class the teacher is teaching when occupied. Changes are done programmatically, not taken from the user.</td>
            </tr>
        </table>

        <h3>Member Functions:</h3>
        <ul>
            <li><code>readData(string inp) - bool</code>: Reads data from the input string and possibly modifies the object's data members accordingly. Returns a boolean indicating the success of the operation.</li>
            <li><code>convertToString() - string</code>: Converts the object's data into a string format.</li>
            <li><code>showTimeTable() - void</code>: Displays the teacher's timetable.</li>
            <li><code>teacher()</code>: Default constructor that initializes the <code>timeTableName</code> 2D array, setting all values to 0.</li>
        </ul>
    </section>
    <section>
        <h2>C++ Class: section</h2>

        <table>
            <tr>
                <th>Data Member</th>
                <th>Data Type</th>
                <th>Purpose</th>
            </tr>
            <tr>
                <td>name</td>
                <td>int</td>
                <td>Represents the name or identifier of the section.</td>
            </tr>
            <tr>
                <td>coreTeachers</td>
                <td>vector of teacher</td>
                <td>Holds a vector of core teachers associated with the section. Corresponding teachers associated with corresponding subjects have the same index in each vector.</td>
            </tr>
            <tr>
                <td>coreSubjects</td>
                <td>vector of subject</td>
                <td>Holds a vector of core subjects associated with the section. Corresponding teachers associated with corresponding subjects have the same index in each vector.</td>
            </tr>
            <tr>
                <td>labSubjects</td>
                <td>vector of subject</td>
                <td>Holds a vector of lab subjects associated with the section. The index corresponds to the lab teacher vector index.</td>
            </tr>
            <tr>
                <td>labTeachers</td>
                <td>vector of vector of teacher</td>
                <td>Holds a vector of vectors of lab teachers associated with the section. Each vector represents lab teachers eligible to conduct classes for a specific lab. The index corresponds to the lab subject index.<b>Each sub vector should at least have 4 teachers since I have defaulted teachers per lab to 2</b></td>
            </tr>
            <tr>
                <td>noOfLabs</td>
                <td>vector of int</td>
                <td>Holds the number of lab rooms required to conduct labs for the respective lab subjects. The index corresponds to both the lab teacher vector and lab subject. <b>Currently program takes this to be 2 if not given as 1.</b></td>
            </tr>
            <tr>
                <td>allRooms</td>
                <td>vector of room</td>
                <td>Holds a vector of all room objects available for allocation.</td>
            </tr>
            <tr>
                <td>defaultRooms</td>
                <td>vector of string</td>
                <td>Represents default rooms used for allocating subjects with no explicitly specified rooms.</td>
            </tr>
            <tr>
                <td>timeTable</td>
                <td>string[days][periods]</td>
                <td>Represents the timetable for the section, indicating the schedule of classes.</td>
            </tr>
            <tr>
                <td>teacherTable</td>
                <td>string[days][periods]</td>
                <td>Represents the timetable for teachers in the section, indicating their schedule of classes.</td>
            </tr>
            <tr>
                <td>roomTable</td>
                <td>int[days][periods]</td>
                <td>Represents the timetable for rooms in the section, indicating their schedule of classes.</td>
            </tr>
        </table>

        <h3>Member Functions:</h3>
        <ul>
            <li><code>addCore(teacher Teacher, subject Subject) - void</code>: Adds core teacher and subject information to the section.</li>
            <li><code>addLab(teacher Teacher[], int noteachers, subject Subject, int noLabs) - void</code>: Adds lab information to the section, including lab teachers, lab subjects, and the number of labs required Second parameter is the number of teacher in the list of teachers given. Will be ommited in future.</li>
            <li><code>displayTimeTable() - void</code>: Displays the timetable for the section.</li>
            <li><code>displayTeacherTable() - void</code>: Displays the timetable for teachers in the section.</li>
            <li><code>displayClassTable() - void</code>: Displays the Class table of the section.</li>
            <li><code>block(int day, int period, string subject, string teacher) - void</code>: Blocks a specific time slot in the timetable for a subject and teacher. Parameters <code>day</code> and <code>period</code> represent the day and period of the timetable, respectively.</li>
            <li><code>makeTIMETABLE() - void</code>: Generates the timetable for the section based on the provided information.</li>
            <li><code>[weight(int &dayfactor, int time, int bfactor) - int]</code>: Calculates a weight based on day factor, time, and bFactor.</li>
            <li><code>[returnRoom(string name) - room&]</code>: Returns a room object from <code>allRooms</code> based on the given room name.</li>
        </ul>
    </section>
    <p><strong>Legend:</strong> Functions enclosed in square brackets [...] are private.</p>

    <footer>
        &copy; 2024 TimeTable Architect. All rights reserved.
    </footer>

</body>

</html>

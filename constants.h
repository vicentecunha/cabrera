#ifndef CONSTANTS_H
#define CONSTANTS_H

// System Files:

const QString RECENT_PATIENTS_FILENAME = "recentPatients.cabrera";
const QString RECENT_ANAMNESIS_FILENAME = "recentAnamnesis.cabrera";

// File Extensions:

const QString PATIENT_EXT = ".pat";
const QString ANAMNESIS_EXT = ".ana";

// File Keywords:

const QString NAME_STRING = "_Name: ";
const QString ID_STRING = "_ID: ";
const QString SEX_STRING = "_Sex: ";
const QString DOB_STRING = "_DoB: ";
const QString NOTES_STRING = "_Notes: ";
const QString HEIGHT_STRING = "_Height: ";
const QString WEIGHT_STRING = "_Weight: ";
const QString CHIEF_COMPLAINT_STRING = "_CC";
const QString HISTORY_PRESENT_ILLNESS_STRING = "_HPI";
const QString PAST_MEDICAL_HISTORY_STRING = "_PMH";
const QString ROS_CARDIOVASCULAR_STRING = "_Cardiovascular";
const QString ROS_RESPIRATORY_STRING = "_Respiratory";
const QString ROS_GASTROINTESTINAL_STRING = "_Gastrointestinal";
const QString ROS_GENITOURINARY_STRING = "_Genitourinary";
const QString ROS_NERVOUS_STRING = "_Nervous";
const QString ROS_CRANIAL_STRING = "_Cranial";
const QString ROS_ENDOCRINE_STRING = "_Endocrine";
const QString ROS_MUSCOSKELETAL_STRING = "_Muscoskeletal";
const QString ROS_SKIN_STRING = "_Skin";
const QString FAMILY_STRING = "_Family";
const QString CHILDHOOD_STRING = "_Childhood";
const QString SOCIAL_STRING = "_Social";
const QString MEDICATIONS_STRING = "_Medications";
const QString ALLERGIES_STRING = "_Allergies";
const QString SEXUAL_STRING = "_Sexual";
const QString CONCLUSION_STRING = "_Conclusion";

// Formats:

const QString DATE_FORMAT = "dd/MM/yyyy";
const QString SAVEFILE_DATE_FORMAT = "dd-MM-yyyy";

// Enumerator strings:

const QString FEMALE_STRING = "Female";
const QString MALE_STRING = "Male";

// Misc:

const int MAX_RECENT_PATIENTS = 8;
const int ID_LENGTH = 10;
const int NUMBER_OF_PATIENT_PARAMETERS = 5;
const int NUMBER_OF_ANAMNESIS_PARAMETERS = 26;

#endif // CONSTANTS_H

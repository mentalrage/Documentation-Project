*** UID:0001SD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-Constant Guidance

Use this folder for named constants, magic numbers, flag masks, resource ids, and sentinel values that are not yet better represented as an enum or macro.

Good candidates include:

- values repeatedly used across a subsystem;
- constants whose source owner header is unclear;
- symbolic names inferred from strings, tables, or API/resource behavior.

Prefer `../by-enum` for closed sets of named values. Prefer `../by-macro` when there is evidence the original source used preprocessor definitions. Prefer `../../by-resource` for concrete resource families.

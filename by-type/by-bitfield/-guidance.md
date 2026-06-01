*** UID:0001S7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-Bitfield Guidance

Use this folder for recovered packed flag fields and bitmask layouts when the bit meanings need their own durable notes.

Good candidates include:

- class or struct fields where individual bits have known behavior;
- protocol or resource flags that are stored in one integer but are not yet a clean enum;
- evidence for `bool : 1`, packed flag bytes, or manual mask constants.

Prefer `../by-enum` when the values are mutually exclusive named states. Prefer `../by-macro` or `../by-constant` when the main question is a named numeric constant rather than the storage layout.

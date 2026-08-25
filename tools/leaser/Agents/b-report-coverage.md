</document_instruction_and_info_start>
Part 1 validator update: this manual tracker is superseded by
`E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\-ag-research-tracker.md`
and the validator executed-report lifecycle commands. Do not manually update
this file as the current source of B-report coverage truth unless the user
explicitly revives it. Use:

```powershell
python .\tools\validator.py execute_report B### report-name.md [TARGETUID] --apply
python .\tools\validator.py execute-rescan-reports --apply
python .\tools\validator.py --mode autogen --apply
```

The validator stores executed reports under
`executed-b-agent-research\B###\`, records target/author/hash metadata in
`tools\validator.ini`, and regenerates `auto-generated\-ag-research-tracker.md`.
Use the validator lifecycle commands for missing/stale executed-report state;
do not edit `tools\validator.ini` or this generated/replaced coverage flow by
hand.
The historical instructions below are retained only as legacy context.

1. This list should contain all items ever targeted by a b agent with a confirmed executed report on that target.

2. Each line should have a filepath of that target, its uid, the filename of the report made, tiemstamp of when the report was completed, and a count of number of times its been covered . Here is an example when there has been multiple reports for 1 item

/by-*/0x-0x.x.md | UID:0004 | 09024-report.md, timestamp | 09055-report.md, timestamp |  2

3. The list should be broken into these catagories
1 catagory for each by-folder and two sub section in each, Items covered that are reconstructable, and items covered that are not reconstructable. If a items reconstructable state has changed then the item entry needs to be moved into the correct subsection.

4. Supervisor is the only one to edit/build/update this list. Also supervisor, WHEN INSTRUCTED, should use this as a guide to help determine new assignments. 

5. If the supervisor is instructed to use this to guide new assignements, supervisor should avoid already covery items and first focus on items marked as reconstructable with no reports written yet. Supervisor should focus on by-memory reconstructable as a priority and then by-item, global, type, etc. This does not mean ONLY do reports on by-memory. This just means focus on those unless reports also line up with needed to improve research on associate items in other folders. Supervisor should also prefer lower scored E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-auto-completion-stats.md reconstructable items not covered vs higher scored not covered items.

6. Supervisor should prefill this list with all needed items that currently exist in the by-folders that have score headers (ignore -1 score items)

7. Make sure to format this document so lookup of sections or items in sections are easily searchable as this file will be gigantic. Use tags to help. I have already created example/starting tags to help. Please change the  format the row lines i provided earlier as an example to a more searchable format with tags if needed if that makes them more easily searchable

8. Any additional rules/changes should be added as additional numbered notes after this one. THE ACTUAL list itself must come after the bracketed document instruction end tag below inside the start list and in the correct section, please add any missing sections. 


</document_instruction_and_info_end>









<start_list>

<by_memory_start>

<by_memory_reconstructable_start>

</by_memory_reconstructable_end>

</by_memory_end>

<by_file_start>

<by_file_reconstructable_start>

</by_file_reconstructable_end>

</by_file_end>



</end-list>

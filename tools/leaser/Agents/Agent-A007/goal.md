## Agent A007 Specific Instructions ##
- Assigned Agent ID: A007
- Use the target-selection guidance below. Do not rely on only one queue or report.

## General Goal ##
Continue improving `E:\NTK\GhidraBridge\source-3\project-documentation\by-*\*.md` documentation and coverage

## Target Selection ##
Use a mix of these sources when choosing work, rather than always starting from one file or one queue:
- `E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\-ag-memory-coverage.md`
- `E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-auto-completion-stats.md`
- `E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-unresolved.md`
- `E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-resolved.md`
- `E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-resolved-multple-aliases.md`
- `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md`

Generated project-state files are read-only inputs. `E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-auto-completion-stats.md`, `E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-resolved-multiple-aliases.md`, `E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-resolved-multple-aliases.md`, `E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-resolved.md`, `E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-unresolved.md`, and all files under `E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated` are automatically generated files. Use them only to review project state and choose targets. Do not modify them directly.

Prioritize items that are unclassified, reconstructable but unassigned, low completion, low confidence, or still use compiler-generated/generated names or aliases. Improve the selected documentation with real analysis and justification so completion/confidence changes are supported by the file's evidence and change log.

## Supervisor Overrides And Existing Rules ##
You do not need direct supervisor permission to improve related documentation required by your assigned target. If accurate work on the target depends on associated by-class, by-file, by-type, by-global, nearby by-memory, or plausible parent/source documents, read them and improve them under normal lease rules. This is especially required when the target itself reaches the score gate but cannot be assigned because the actual direct source/owner is unresolved: investigate and improve the plausible parent/source candidates enough to prove or reject direct ownership. If no single direct owner can be proven, report which related documents were checked or improved, their before/after scores, and why assignment still fails.

Supervisor or batch directives override only the specific instructions they directly conflict with, usually target selection. All non-conflicting instructions in this goal, `by-structure.md`, validator rules, lease rules, naming/renaming rules, coverage-report rules, and documentation quality requirements remain active. An assigned target is an entry point, not a hard boundary on scope. If you discover existing problems while working, you are expected to repair them when possible, including mixed ownership, bad memory ranges, overbroad files, missing nested memory items, missing by-structure splits, stale filenames, bad parent links, stale coverage rows, unjustified scores, and incomplete or inaccurate evidence. If a memory item needs to be split into nested children under `by-structure.md`, do the split instead of ignoring the existing problem. If the repair is blocked by leases or missing evidence, record the exact blocker in `notes.md` and continue useful work. The goal is accurate documentation, not merely reducing unassigned counts.

## Required General Instructions and Documented Information Sources ##
1. `E:\NTK\GhidraBridge\source-3\project-documentation\by-structure.md` *Required Reading*
2. `E:\NTK\GhidraBridge\source-3\project-documentation\by-project-structure\proposed-source-tree.md` is the current proposed final project structure. Use it as reference when making by-file changes. Do not directly edit this non-`by-*` file; if it needs an update, record the follow-up in your `notes.md` or use an approved tool if one exists.
3. `E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated` Contains the auto-generated final project and also coverage reports. These can be used to find and work on sources missing reconstructable marks, or other leads into what needs work
4. `E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-auto-completion-stats.md` Shows general completion for documents, files missing paths, etc. 
5. `E:\NTK\GhidraBridge\source-3\project-documentation\project-level\` `-resolved-multple-aliases.md`, `-resolved.md`, `-unresolved.md` for tracking compiler generated names and aliases

## Tools ##
- Tool concurrency note: There may be many agents running at the same time. Any tool call may occasionally time out or return transient errors because too many calls are happening at once. If this happens, wait briefly and try the same command again a few times before treating it as a real blocker.
- IDA MCP: Please read `E:\NTK\GhidraBridge\source-3\project-documentation\by-structure.md` for general IDA MCP USAGE
- validator.py: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py` | README: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator_README.txt` | Main tool for referencing / generating UIDS / and generating coverage and simulated files.
- unresolved.py `E:\NTK\GhidraBridge\source-3\project-documentation\tools\unresolved.py` | README: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\unresolved_README.txt` | For tracking compiler generated names and aliases
- leaser.py `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\leaser.py` | README: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\README.md` | For preventing collisions between multiple agents working on files

## LEASING ##
- Before MODIFYING a document, read current lease status through your per-agent symlink at `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-A007\current_leases.md` instead of running leaser.py info commands. This symlink is the approved way to read the generated lease report from inside your own agent folder. Remember you must REGISTER a new lease and get a success message before editing any file. Remember that you may only edit YOUR LEASES.
- Only call leaser.py when you need to add or remove a lease. Use your assigned Agent ID for every `lease` and `unlease` command, and never send commands as a different agent. Do not run `python leaser.py leases`, `python leaser.py *AgentID* leases`, or `python leaser.py *AgentID* leases all`; when report-file mode is enabled those info commands are rejected and agents must read `current_leases.md` instead.
- Never edit `current_leases.md` or any symlink to it.
- Do not directly modify any file under `E:\NTK\GhidraBridge\source-3\project-documentation\tools` except files inside your own assigned agent folder. Your own folder exception exists only for reading `goal.md`, reading/updating `notes.md`, and reading your `current_leases.md` symlink/report as instructed.
- Do not directly read or edit tool internals such as `.ini`, `.json`, `.lock`, validator/leaser code, or validator/leaser state/data files. Call the tools through their documented commands instead of opening or changing their code/config/state.
- You do not need a lease to read a file. You may read files leased to yourself or leased to other agents, but remember those files may be actively changing and the data you read may already be out of date.
- If the specific target document you want to edit is leased by another agent and it is not a `-coverage-report.md` file, assume that document is already being actively worked on. Do not wait on it or edit it; pick another target instead.
- Do not try to lease files that do not exist. If a by-structure split requires new child files, lease the existing parent item being split and any other existing files you will edit, create the new child file(s), then lease the newly created child file(s) before further edits if needed. A `File not found` result for a non-existent child path means you attempted the lease too early; it is not a blocker by itself.
- Always update `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md` when you change by-memory docs. If this coverage report is leased, keep working on any target docs you can lease, record the exact needed coverage rows/changes in your `notes.md`, and apply those report updates later when the report is free.
- If any other shared report, generated coverage file, validator state file, or large master file is unavailable, do not stop. Record the exact tool command or by-* documentation/report change needed in `notes.md`, then continue with other useful work. Do not directly edit generated/project-level/tool state files to finish these follow-ups; call the appropriate tool when that tool-owned update is needed.
- AGAIN DO NOT STOP WORKING IF A ITEM YOU NEED TO MODIFY IS LEASED. For locked target docs, move to another target. For locked shared/report files needed to finish work you already completed, create a temporary note at `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-*ID  NUMBER*\notes.md` and move onto working on something else. DO NOT WASTE TIME. Remember you can still read leased files, you just cant edit them.
- Remember to RELEASE your lease after you are done editing.
 
## Notes ##
- Notes are placed at `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-*ID  NUMBER*\notes.md`
- You must only track updates you need to make to locked files. Once file beomes availible please apply the needed changes and then REMOVE THAT SPECIFIC NOTE. Always clean up executed tasks inside your note file.
- The 100-line limit applies only to progress logs, general follow-ups, and other notes that are not pending updates blocked by leased files. Pending updates that cannot be pushed because files are leased are exempt from the 100-line limit; use as many lines as needed to document exact pending changes, and remove each pending note after applying it.
 
## Rules ##
1. Do not use wave3/wave2 source data and instead rely solely on ida mcp and existing documentation files iunder project-documentation
2. Do not commit updates via git unless told to.
3. Direct manual edits are limited to files inside `E:\NTK\GhidraBridge\source-3\project-documentation\by-*` folders and files inside your own `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-A007` folder.
4. Do not directly edit files outside a `by-*` folder, including `auto-generated`, `project-level`, `by-project-structure`, and tool-owned/config/state files. The only exception is your own agent folder for `notes.md` updates and reading your assigned instructions/report symlink.
5. Do not directly read `.ini`, `.json`, `.lock`, tool state/data files, or tool source/config under `E:\NTK\GhidraBridge\source-3\project-documentation\tools`. Use tool commands instead of opening or changing tool internals.
6. Do not edit files leased to other agents, remember to lease your files, remember to release your lease after edits are complete.
7. If this job was given to you as a goal, your goal is never complete. You must continue work effectively forever, never stopping. Continue to improve project-documentation.

## Keep In Mind ##
1. When making large updates ensure any files referencing your target file are also kept up to date.
2. Remember that by-memory objects should be correctly/split and nested. If a class is listed it should also have nested by-memory .mds covering smaller ranges of its contents. Even if not working on by-memory directly ensure content you are working on
is correctly built in by-memory
3. Remember that items should be marked reconstructable if they contain custom game code that needs to be recreated in the new binary. CRT/Built In code is not reconstructable. For Static Embeded Third Party librarys please review by-structure.md for specific rules.
4. For reconstructable items, do not attach children to parent items unless both have 80%+ confidence/completion
5. Do not write final reconstruction C++ in reconstructable documents unless it reaches the 95/95 bar.
6. Do not blindly improve confidence/completion scores without doing full analysis and justifying it with improved research/docmentation in the targeted document. Ensure the change/modification log in each file also justifys each change with good reasoning.
7. Update manual coverage reports when by-memory docs change. If `by-memory\-coverage-report.md` is leased, record the exact needed row changes in `notes.md` and apply them later.
8. Rename files when the documented identity changes. For example, if a by-memory range changes, rename the file to the corrected range; if a by-class class name changes, rename the class file to match. Validator can handle these filename changes automatically.
9. Remember to cross reference between files, and keeping data updated and accurate between them.
10. Remember to update by-meta files, and create new meta documents when needed for uncovered topics. Remember you can use these as additional information.
11. Remember that files prefixed with `-` are meta/additional files on that topic. Please check those as they have additional information and instructions.
12. Consider this task efectively never complete. You can always create more detailed documentation once full binary documentation has been completed


Validator.py update

Please update the validator.py code
in auto-generated folder create a new file called

-ag-research-tracker.md

Move all executed research from all agents to
E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research
have a folder for each agent id and all EXECUTE research reports include ones marked as older should be moved here
Create an additional unknown folder for reports that have a unknown author

the new feature will replicate and automate what this document was attempting to do manually
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\b-report-coverage.md

It will generate a similar report based on what was described.
It will detect executed reports autoamtically based on files that are in E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research

It will also build the initial list based on all files currently in by-documents and assume there are no reports, it will add all the rows and mark them as not covered.
Then it will search the executed folder and match them to the file and mark them as researched.
However current reports may not have a reliable way to detect exactly what each report targetted. You will need to confirm it can detect it and if not, manually add a tag to the top to force detection and it should be formatted like this ** TARGET-REPORT-UID:#### ** (We will also need a secodnary agent auther header mentioned below) These headers should work similarly to headers in by-x files  
All research documents will eventually be required when written by agents to have this line at the top but all existing reports currently do not support this. You have to ensure the correct uid is chosen. AT THE END OF THE GENERATE FILE HAVE A ERROR SECTION THAT LISTS ANY PROBLEMS WITH REPORTS THAT EXIST LIKE THE TARGETED UID/FILE CANNOT BE FOUND

When validator created a new uid from now on you need to ensure this also updates this generated file automatically. It should gain a new row for that file. Only the intial first run will do the mass auto detection. 

the ini for the current fiels should probably track this with additional propertys for each uid in validator so maybe something like research-reports: filepath, filepath etc for each report. The count can be derivered from the amount of paths found.?

Supervisor will no longer manually move executed reports from the agent folders to the executed folder. Sueprvisor will call a validator command like validator execute_report agent_id report-filename. Validator will then lookup the agent path under leases and find its id, then go into the research folder and find the supplied matching filename. It will then move that file to the new location, and add the required inforation in the ini about that new report like mentioned above. Supervisor should also have an additional ovverride like execute_report agent_id report-filename targetUID -> this will automatically check if the **target-uid header is correctly at the top of the document and if not add it then insert the uid. If it already does have that header it will replace the uid with the override provided one.

there will also be a invalidate_execute agentid report-filename that will move the file BACK into the agents research folder and remove the info from the ini. This is if the supervisor decides the report was invalid and needs to be reworked.

The top of the ag file should contain some stats like Coverage for each catagory and coverage for each supcatgory. So it should say like by-memory reconstructable covered 55% by-memory not reconstrucable covered 20% and so on

Additionally each uid should maintain a hash of the filesize of each report when its first entered, this is to track if the file was modified in the new execute location AFTER it was executed. There should be an additional option validator execute-rescan-reports that will rescan all reports and recheck hashes, if filesized changed after inital entry this will also be reported in the error section that there was a change. 

The correct way to fix this is for the supervisor to revalidate the changed item and call execute-confirm-change agentid filename to rehash the file once they confirm that the report is still good. THey can ALSO invalidate the report sending it back to the original agent and then execute it again.

make sure the correct agent is always required in the commands do not allow writting a different agent id with the filename. So if agent b001 is supplied it will only search for the report in the bb0001 agent research folder and will only search for executed reports in the new executed reports folder of that agent
Only exception is the unknown folder. 

Add a extra executed-reassign original-agentid/unknown new_id which will reassign the agent. This only works on files already in executed. It will also move the file to the new location

If there are ever duplicate report names, like if executing a report and there is already a report in that agents location with the same name, the report should automatically be appended with a number at the end so it doesnt overwrite the original. Make sure code handles this change internally and points to the renamed file.

Instead of just two subcatagoies for each by memory folder there will now be this new format

By-Folder Main Catagory
    Not-Covered Files
	    Reconstructable Sorted by completion/confidence average (of both completion and confidence) low to high
		Not Reconstructable Sorted by completion/confidence average (of both completion and confidence) low to high
	
	Covered Files
	    Reconstructable Sorted by times covered and then by the LAST time/most recent covered file timestamp
		Not Reconstructable Sorted by times covered and then by the LAST time/most recent covered file timestamp
Ensure the statistics remarks above reflect this

		
The validator should try to track changes to files, such as reports, modifications, score updates etc efficently and update this file attomicalyl
it should not have to recalculate everything from scratch. IE when a file becomes covered it should recheck its score and update accordingly, this should be written efficently


all skills in the project will need to be updates as well if needed. Sueprvisor instructions regarding manual execution needs to be changes to reference the new format of calling the tool. And also instruct about its usage other commands etc.
Agent skills need to be aware that they are now required to have a *target-uid** header as well as a **author-agent-id:bxxxx** header at the top of each report and that the supervisor should reject if these two headers are missing and filled out

make sure that there is a skeleton framework to support erports for other agent types in the future like a/c agents, and also have their counts/files seperate from other agents so they are not mixed togeter in data.


2nd update - We are automating coverage reports with validator as well. All existing coverage reports will be kept intact but a new file for each item where we will autoate coverage reports will be created at E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\-ag-coverage-report-by-*.md
This will automatically create a simialr report to how the existing coverage reports look. For the initial update we will ONLY auto generate the coverage report for by-memory
We can infer the initial nesting based on how it is currently formated in the existing coverage report
The auto convereage report will auto sort the same way by memory-address and then nest items.
The tool will need to inject new header tags into all files (only by memory for now since we are only supporting that) such as 
*** Item Summary : *** which will contain the summary that current coverage report uses

Here is a current example of a real coverage report item
- [UID:00039Y][0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers](by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md) 0x005590e0-0x0055916b | method/helper cluster | ScreenPaneCallbackAndFlagHelpers : reconstructable : 88% : very-strong : B005 2026-06-19 source-quality reanalysis reroutes the direct owner/emitter to [UID:0000CB][ScreenPane](by-class/ScreenPane.md) through [UID:0000NB][ScreenPane](by-file/ScreenPane.md), names `sub_5590E0`/`sub_559110` as `QueueFadeInCallback`/`QueueFadeOutCallback` for `FdIn`/`FdOt` screen fade events, resolves `this+0x5a4` as the ScreenPane fade/presentation transition state, preserves raw `0x00559140`/`0x00559160` as retained `SetFadeTransitionState`/`IsFadeTransitionActive` helpers with no direct xrefs, confirms exact internal padding including `0x00559151-0x00559160`, and recommends first-draft C++ while capping completion for raw-helper liveness plus final header/member spelling.

The auto generator will automatically add this part [UID:00039Y][0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers](by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md 0x005590e0-0x0055916b | since it can all be grabbed froma vailible info, reconstructable can be pulled from the contained tags, emits code /true false should be added automatically 
source-quality reanalysis reroutes the direct owner/emitter to [UID:0000CB][ScreenPane](by-class/ScreenPane.md) through [UID:0000NB][ScreenPane](by-file/ScreenPane.md), names `sub_5590E0`/`sub_559110` as `QueueFadeInCallback`/`QueueFadeOutCallback` for `FdIn`/`FdOt` screen fade events, resolves `this+0x5a4` as the ScreenPane fade/presentation transition state, preserves raw `0x00559140`/`0x00559160` as retained `SetFadeTransitionState`/`IsFadeTransitionActive` helpers with no direct xrefs, confirms exact internal padding including `0x00559151-0x00559160`, and recommends first-draft C++ while capping completion for raw-helper liveness plus final header/member spelling. this part would be the summmary
also a timestamp of when this item was last updated should be auto included in each line
You may need to also ad a *** Nested: -# 0 -> # *** automatically. This will control if the item is nested or not. Settign this to 1 will cause it to be nested under the next highest memory address.

so if  - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005590da-0x005590e0 | padding | ScreenPaneCursorResourceLoader to ScreenPaneCallbackAndFlagHelpers alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:00039Y][0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers](by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md) 0x005590e0-0x0055916b | method/helper cluster | ScreenPaneCallbackAndFlagHelpers : reconstructable : 88% : very-strong : 

If uid:00039Y adds nested 1

the autogen will tab that line under 0000vn (remember that memory ordering should never change). ADditionally you can write 0 to keep it at whatever level the higher item is so 0 will be on the same level as the address above it (when I say above i mean in regards to list order not memery address number)
setting a negative value will lift it up above. There is a max cap on lift considered the global level, so setting -1000 will not raise a item higher than all existing items by 1000, it will not tab all items a billion times

make sure the code that updates the autogen file makes these edits efficently.

additionally pleae investigate validator.py and multithread any operations that it runs currently that dont need to be run serially. Like calling a file scan may need to update 5 different autogen files of different types. The main data changes should be done in the ini, and file edits should be run in seperate threads to edit each file individually based on that original data if possible
Just make sure in cases like validator.py updates filea and fileb and it spawns 3 worker theads updating each file, there is only 1 unique worker per file edited, so for isntance 1 worker will only edit ag-xxx.md and 1 worker only edits ag-autogetx.md. That way two workers cannot conflict editing the same file

once this is done skills and documentation need to be updated to reference this, instructions to manually update by-memory coverage report should be removed.


Please create a plan at E:\NTK\GhidraBridge\source-3\project-documentation\tools\updates\validator_update_plan.md
It should contain full implementation details, and contain no gaps, errors, and be optimized as possible. Making sure there are no regressions
Once you complete the plan you must review the plan and check for isssues and fix them. EVerytime you find issues you must do another review.
Once you complete 2 reviews with no issue you must implement the plan in full. Make sure you do dry runs etc and ensure output is correct.
YOu do not need to create backups of existing files as I have done so already, however you should do dry runs and confirm existing files, data etc are not damaged. Once you can cofirm that you must run the full program without a dry run to confirm tis 100% operational
Please always check and theorize edge cases and code against those.

DO NOT EDIT THIS FILE. ONLY WRITE THE PLAN TO THE E:\NTK\GhidraBridge\source-3\project-documentation\tools\updates\validator_update_plan.md

ALSO DO NOT MODIFY ANY INSTRUCTIONS/SKILLS UNTIL YOU HAVE FULLY RUN THE PROGRAM WITH CHANGES WITHOUT DRY RUN ACTIVE. ADDITIONALLY AFTER YOU COMPLETE THE CODE AND CONFIRMED ITS FULLY FUNCTIONALITY STOP AND ASK USER TO IMPLEMENT THE NEEDED SKILL/INSTRUCTION UPDATES.
YOU ARE ALLOWED HOWEVER TO UPDATE TOOL READMES JUST AVOID ANYTHING INTENDED FOR AGENTS/SUPERVISORS

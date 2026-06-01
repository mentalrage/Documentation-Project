*** UID:000205 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Legacy Wave2 Stage Notes

This file preserves older Wave2 report/staging instructions that previously lived in `by-memory/-guidance.md`.

Use this only as historical context or when explicitly doing an older Wave2 staging pass. Current documentation workflow is governed by `../by-structure.md`, `-guidance.md`, and `../tools/validator_README.txt`.

## Wave2 Status Reference

INTEGRATED: already in Wave2 imported classes/globals
MISSING_REF: not integrated, but currently present in the live missing-ref backlog
DOCUMENTED_ONLY: present in exported function data, but not integrated and not in live missing-refs
UNDOCUMENTED: not found in any of the above

## Symbol Reference

These symbols at the start of each line have the following meanings. Additionally multiple symbols may be used in combination
*: (Stage 1 Marker) - These are covered in report.md
**: (Stage 2 Marker) - These are covered in report.md and 2nd pass verification (Stage 2) has been done on the item.
X: (Stage 3 Marker) - These items are marked as having no action needed. (Runtime/Already Integrated etc...)
@: (Stage 3 Marker) - These items require action. (Do not remove after # symbol has been added)
#: (Stage 4 Marker) - These marks items that required action (@) has been completed (meaning integrated/updated in wave2.py)

## Guidance

Note - You have already reached Stage 5

Stage 1: (Report Writting): Generate a report for each line in report.md. Add a asterisk to each item when a report is made. (Example *NUMBER)
Stage 2: (Verification): Review each item in the report. Double check all data for accuracy. Do additiional research if data is complete. Once done append a 2nd asterisk. (Example **NUMBER) to the start of matching line item.
Stage 3: (Marking): Mark ALL Verified Actionable items with a @ or Inactionable items with a X. (Example: Lines should now look like **@NUMBER or **XNUMBER)
Stage 4: (Integration): Integrate each verified actionable item as described. Once Integrated/Updated please ensure line is marked with # (Example **@#NUMBER) to signify all work for item is complete
Stage 5: (Freeform) If all previous work is completed please use ida mcp and availible tools to see if there are other missing undocumented methods/classes/globals/other data types and integrate them by repeating the process above.
- Add them to this document, add new reports to report.md, proceed though the stages as required.
Additionally fix any additional issues you come accross in the wave2 code as you go.
--Examples of this are raw sub calls, missing methods/globals, bad or missnamed items, differing naming patterns, decomp artifacts, items that should not be excliuded in wave2.py that are, or items that are excluded in wave2.py but should not be. Please remember high grades does not mean the target is accurate, only correct to some standards.
Do not merely just update the reports. This pass should be fixing all issues in wave2.py code as they are found.
Please remember all code must be accurate to the original source but fully converted to human written c++ code
Additionally if there are bugs or missing features in wave2.py that are required please fix/add them as you go.
- Items that are real game logic should only be marked non reconstructable as a last research. As these items are found full investigations should be launched to fully reveal the item and give it proper documentation and assignment.

## Notice

Please remember project goal is exact reconstruction of original program back into c++ resembling the code developers had before original compilation. Please avoid skipping custom NEXUSTK code as this would alter its output from the original. With this in mind please try to avoid std/crt/other code as this is not needed. The original source code was lost and only the exe remains. We need to restore code so it functions as a real working compileable project.

## Tools

Please remember to use wave2.py functionality for information lookup as well as updating and modifying the code itself.
YOU MUST USE WAVE2.PY TO UPDATE CODE

You may additional use ida mcp at this address
  Streamable HTTP: http://127.0.0.1:13337/mcp
  SSE: http://127.0.0.1:13337/sse
  Config: http://127.0.0.1:13337/config.html
- You will have to MANUALLY figure out how to send commands to this tool as its not exposed directly. This should not be a problem as you have done this before. Please add any notes directly below this line with instructions on how to do this if needed for future reference.
- Manual note: direct JSON-RPC `POST` requests to `http://127.0.0.1:13337/mcp` work from PowerShell. A safe flow is `initialize` -> `tools/list` -> `tools/call`.
- Working PowerShell pattern:
  `$body = @{jsonrpc='2.0'; id=1; method='tools/call'; params=@{name='lookup_funcs'; arguments=@{queries='0x00576660'}}} | ConvertTo-Json -Depth 8`
  `Invoke-RestMethod -Uri http://127.0.0.1:13337/mcp -Method Post -ContentType 'application/json' -Body $body | ConvertTo-Json -Depth 10`
- Useful methods:
  `initialize` with `@{protocolVersion='2025-03-26'; capabilities=@{}; clientInfo=@{name='codex-manual'; version='1.0'}}`
  `tools/list` with empty params
  `tools/call` with `params.name='<tool>'` and `params.arguments=@{...}`
- Confirmed locally in this repo: `lookup_funcs`, `tools/list`, and `initialize` all responded successfully through `/mcp`.

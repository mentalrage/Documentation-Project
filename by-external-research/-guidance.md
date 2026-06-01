*** UID:0000GF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-External-Research Guidance

Use this directory for outside information that may help reverse engineering: fan sites, official or archived websites, third-party repositories, historical tool/library notes, forum posts, screenshots, manuals, and other context not produced from the local binary.

Treat all external research as lead material, not proof. Claims from this folder should not raise reconstruction confidence unless they are later verified against IDA/MCP, local binary evidence, DAT/resource evidence, or reviewed generated data.

Because these pages are supporting research rather than direct binary reconstruction units, they should normally be scored `COMPLETION:-1` and `CONFIDENCE:-1`.

## Page Contents

Each external-research page should include:

- source URL, archive path, local file path, repository commit, or other stable citation when available;
- access or capture date when useful;
- short summary of the external claim or evidence;
- why the source may matter for NexusTK reconstruction;
- local verification status: unverified lead, partially verified, contradicted, or confirmed by local evidence;
- links to relevant `../by-meta`, `../by-file`, `../by-class`, `../by-resource`, or `../by-memory` docs once the lead is connected to binary evidence.

Do not store large third-party payloads directly as prose pages when they belong under a dedicated evidence folder such as `../by-meta/obtained_thirdparty_files`. Summarize what matters here and link to the stored payload or external source.

## Coverage Report Rows

External-research pages are lead material rather than direct binary reconstruction units, so rows should normally be scored `-1`. Use the source/topic name as the row key in `-coverage-report.md`, and keep ignored rows for leads that have been disproven, superseded, or moved into a better local documentation home.

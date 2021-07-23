# Metadata extractor

### Installation

```bash
sudo apt-get update
sudo apt-get install -y libcurl4-openssl-dev
cd metadata_from_url
make
```

### Invocation example

```bash
./extractor https://interestingengineering.com/canada-is-banning-internal-combustion-engines-but-what-about-the-cold
```

### Output example

```json
{
	"metadata": [
		{ "description": "IE=edge" },
		{ "keywords": "Electric vehicles, cold weather, batteries" },
		{
			"og:title": "Canada Just Announced A Ban on Internal Combustion Engines"
		},
		{
			"og:description": "Canada and Norway will soon ban ICE cars, but what about the cold?"
		},
		{ "og:type": "article" },
		{
			"og:url": "https://interestingengineering.com/canada-is-banning-internal-combustion-engines-but-what-about-the-cold"
		},
		{
			"og:image": "https://inteng-storage.s3.amazonaws.com/img/iea/r1OrW3DQGn/sizes/evs-in-cold_md.jpg"
		},
		{
			"og:image:alt": "Canada Just Announced A Ban on Internal Combustion Engines"
		},
		{ "fb:pages": "139188202817559" },
		{ "fb:app_id": "467815213795758" },
		{ "msapplication-TileColor": "#007FC0" },
		{
			"msapplication-TileImage": "https://assets.interestingengineering.com/icons-v2/ms-icon-144x144.png?v=15"
		},
		{ "theme-color": "#007FC0" },
		{ "csrf-token": "cJJy9LolyNkq955zdtv5i61cMWkKgLymixEYBTfP" },
		{ "og:image:width": "864" },
		{ "og:image:height": "486" },
		{ "article:published_time": "2021-07-02T12:54:00-05:00" },
		{ "article:modified_time": "2021-07-02T18:20:04-05:00" },
		{ "og:updated_time": "2021-07-02T18:20:04-05:00" },
		{ "twitter:card": "summary_large_image" },
		{ "twitter:site": "@IntEngineering" },
		{
			"twitter:title": "Canada Just Announced A Ban on Internal Combustion Engines"
		},
		{
			"twitter:description": "Canada and Norway will soon ban ICE cars, but what about the cold?"
		},
		{
			"twitter:image": "https://inteng-storage.s3.amazonaws.com/img/iea/r1OrW3DQGn/sizes/evs-in-cold_md.jpg"
		},
		{ "twitter:creator": "@IntEngineering" }
	]
}
```
